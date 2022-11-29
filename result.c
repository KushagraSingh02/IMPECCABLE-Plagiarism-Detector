int display_files(char *folder_name)
{
    newline(2);
    tab(3);
    int number_of_files=0;
    struct dirent **name_list;
    int n;
    int i=0;
    int j=0;
    n = scandir(folder_name, &name_list,NULL,alphasort);
    printf("Current Directory:\t%s",getcwd(NULL,0));
    newline(2);
    tab(5);
    printf("Files Present in Current Directory");
    newline(3);
    int number_of_columns=4;
    int column_length=30;
    tab(1);
    while(i<n)
    {
        if(strcmp(name_list[i]->d_name,"..")==0 || strcmp(name_list[i]->d_name,".")==0)
        {
            free(name_list[i]);
            ++i;
            continue;
        }
        printf("%s", name_list[i]->d_name);
        space(column_length-(strlen(name_list[i]->d_name)));
        free(name_list[i]);
        ++i;
        ++j;
        if(j%number_of_columns==0)
        {
            newline(2);
            tab(1);
        }
    }
    free(name_list);
    newline(3);
    tab(3);
    return (n-2);
}

bool write_results(data *source_data, data *destination, bool success,float parameters_matching_percentage,float function_matching_percentage,float statement_matching_percentage)
{
    FILE *fptr;
    chdir("..");
    chdir("Results");
    char file_name[96];
    strcpy(file_name,"Result_");
    strcat(file_name,source_data->name_of_file);
    strcat(file_name,"_");
    strcat(file_name,destination->name_of_file);
    strcat(file_name,"_");
    strcat(file_name,".txt");
    fptr=fopen(file_name,"w");
    if(fptr==NULL)
        return false;
    fprintf(fptr,"\n\n\t\t\t");
    if(success)
        fprintf(fptr,"SUCCESS LOG! ");
    else
        fprintf(fptr,"FAILURE LOG! ");
    fprintf(fptr,"Details");
    fprintf(fptr,"\n\n");
    float cumulative_matching_percentage=parameters_matching_percentage+function_matching_percentage+statement_matching_percentage;
    cumulative_matching_percentage/=3;
    fprintf(fptr,"\tCumulative Matching Percentage: %.2f\n",cumulative_matching_percentage);
    fprintf(fptr,"\tParameter Matching Percentage: %.2f\n",parameters_matching_percentage);
    fprintf(fptr,"\tFunction Matching Percentage: %.2f\n",function_matching_percentage);
    fprintf(fptr,"\tStatement Matching Percentage: %.2f\n",statement_matching_percentage);
    fprintf(fptr,"\n");
    fprintf(fptr,"\tDetails of Source File\n\n");
    fprintf(fptr,"Name of File: %s\n",source_data->name_of_file);
    fprintf(fptr,"Number of Functions: %d\n",source_data->number_of_functions);
    fprintf(fptr,"Function Wise Details\n");
    for(int i=0;i<source_data->number_of_functions;i++)
    {
        fprintf(fptr,"Function %d\n",i+1);
        fprintf(fptr,"Name of Function: %s\n",source_data->function[i].name);
        fprintf(fptr,"Return Type: %s\n",source_data->function[i].return_type);
        fprintf(fptr,"Number of Arguments: %d\n",source_data->function[i].number_of_arguments);
        fprintf(fptr,"Number of int arguments: %d\n",source_data->function[i].number_of_int_arguments);
        fprintf(fptr,"Number of char arguments: %d\n",source_data->function[i].number_of_char_arguments);
        fprintf(fptr,"Number of float Arguments: %d\n",source_data->function[i].number_of_float_arguments);
        fprintf(fptr,"Number of bool Arguments: %d\n",source_data->function[i].number_of_bool_arguments);
        fprintf(fptr,"Number of long Arguments: %d\n",source_data->function[i].number_of_long_arguments);
        fprintf(fptr,"Number of double Arguments: %d\n",source_data->function[i].number_of_double_arguments);
        fprintf(fptr,"Number of int Variables: %d\n",source_data->function[i].number_of_int_variables);
        fprintf(fptr,"Number of char Variables: %d\n",source_data->function[i].number_of_char_variables);
        fprintf(fptr,"Number of float Variables: %d\n",source_data->function[i].number_of_float_variables);
        fprintf(fptr,"Number of bool Variables: %d\n",source_data->function[i].number_of_bool_variables);
        fprintf(fptr,"Number of long Variables: %d\n",source_data->function[i].number_of_long_variables);
        fprintf(fptr,"Number of double Variables: %d\n",source_data->function[i].number_of_double_variables);
        fprintf(fptr,"Number of printf Statements: %d\n",source_data->function[i].number_of_print_statements);
        fprintf(fptr,"Number of scanf Statements: %d\n",source_data->function[i].number_of_scan_statements);
        fprintf(fptr,"Number of for loops: %d\n",source_data->function[i].number_of_for_loops);
        fprintf(fptr,"Number of while loops: %d\n",source_data->function[i].number_of_while_loops);
        fprintf(fptr,"Number of if Statements: %d\n",source_data->function[i].number_of_if);
        fprintf(fptr,"Number of else if Statements: %d\n",source_data->function[i].number_of_else_if);
        fprintf(fptr,"Number of else Statements: %d\n",source_data->function[i].number_of_else);
        fprintf(fptr,"Number of break Statements: %d\n",source_data->function[i].number_of_break);
        fprintf(fptr,"Number of continue Statements: %d\n",source_data->function[i].number_of_continue);
        fprintf(fptr,"Total Number of Lines: %d\n",source_data->function[i].number_of_statements);
        fprintf(fptr,"\n");
    }
    fprintf(fptr,"\tProgram Details Continued...\n");
    fprintf(fptr,"Number of Lines: %d\n",source_data->number_of_lines);
    fprintf(fptr,"Number of scanf Statements: %d\n",source_data->number_of_scan);
    fprintf(fptr,"Number of printf Statements: %d\n",source_data->number_of_print);
    fprintf(fptr,"Number of for loops: %d\n",source_data->number_of_for);
    fprintf(fptr,"Number of while loops: %d\n",source_data->number_of_while);
    fprintf(fptr,"Number of if Statements: %d\n",source_data->number_of_if);
    fprintf(fptr,"Number of else Statements: %d\n",source_data->number_of_else);
    fprintf(fptr,"Number of else if Statements: %d\n",source_data->number_of_else_if);
    fprintf(fptr,"Number of break Statements: %d\n",source_data->number_of_break);
    fprintf(fptr,"Number of int Variables: %d\n",source_data->number_of_int);
    fprintf(fptr,"Number of float Variables: %d\n",source_data->number_of_float);
    fprintf(fptr,"Number of char Variables: %d\n",source_data->number_of_char);
    fprintf(fptr,"Number of long Variables: %d\n",source_data->number_of_long);
    fprintf(fptr,"Number of double Variables: %d\n",source_data->number_of_double);
    fprintf(fptr,"Number of bool Variables: %d\n",source_data->number_of_bool);
    fprintf(fptr,"Number of Included Header Files: %d\n",source_data->number_of_include);
    fprintf(fptr,"Number of #define pre-processors: %d\n",source_data->number_of_define);
    fprintf(fptr,"Number of Structures: %d\n",source_data->number_of_struct);
    fprintf(fptr,"Number of typedef: %d\n",source_data->number_of_typedef);
    fprintf(fptr,"Number of void Functions: %d\n",source_data->number_of_void_functions);
    fprintf(fptr,"Number of int Functions: %d\n",source_data->number_of_int_functions);
    fprintf(fptr,"Number of float Functions: %d\n",source_data->number_of_float_functions);
    fprintf(fptr,"Number of char Functions: %d\n",source_data->number_of_char_functions);
    fprintf(fptr,"Number of bool Functions: %d\n",source_data->number_of_bool_functions);
    fprintf(fptr,"Number of long Functions: %d\n",source_data->number_of_long_functions);
    fprintf(fptr,"Number of double Functions: %d\n\n\n",source_data->number_of_double_functions);
    fprintf(fptr,"\tDetails of Destination File\n\n");
    fprintf(fptr,"Name of File: %s\n",destination->name_of_file);
    fprintf(fptr,"Number of Functions: %d\n",destination->number_of_functions);
    fprintf(fptr,"Function Wise Details\n");
    for(int i=0;i<destination->number_of_functions;i++)
    {
        fprintf(fptr,"Function %d\n",i+1);
        fprintf(fptr,"Name of Function: %s\n",destination->function[i].name);
        fprintf(fptr,"Return Type: %s\n",destination->function[i].return_type);
        fprintf(fptr,"Number of Arguments: %d\n",destination->function[i].number_of_arguments);
        fprintf(fptr,"Number of int arguments: %d\n",destination->function[i].number_of_int_arguments);
        fprintf(fptr,"Number of char arguments: %d\n",destination->function[i].number_of_char_arguments);
        fprintf(fptr,"Number of float Arguments: %d\n",destination->function[i].number_of_float_arguments);
        fprintf(fptr,"Number of bool Arguments: %d\n",destination->function[i].number_of_bool_arguments);
        fprintf(fptr,"Number of long Arguments: %d\n",destination->function[i].number_of_long_arguments);
        fprintf(fptr,"Number of double Arguments: %d\n",destination->function[i].number_of_double_arguments);
        fprintf(fptr,"Number of int Variables: %d\n",destination->function[i].number_of_int_variables);
        fprintf(fptr,"Number of char Variables: %d\n",destination->function[i].number_of_char_variables);
        fprintf(fptr,"Number of float Variables: %d\n",destination->function[i].number_of_float_variables);
        fprintf(fptr,"Number of bool Variables: %d\n",destination->function[i].number_of_bool_variables);
        fprintf(fptr,"Number of long Variables: %d\n",destination->function[i].number_of_long_variables);
        fprintf(fptr,"Number of double Variables: %d\n",destination->function[i].number_of_double_variables);
        fprintf(fptr,"Number of printf Statements: %d\n",destination->function[i].number_of_print_statements);
        fprintf(fptr,"Number of scanf Statements: %d\n",destination->function[i].number_of_scan_statements);
        fprintf(fptr,"Number of for loops: %d\n",destination->function[i].number_of_for_loops);
        fprintf(fptr,"Number of while loops: %d\n",destination->function[i].number_of_while_loops);
        fprintf(fptr,"Number of if Statements: %d\n",destination->function[i].number_of_if);
        fprintf(fptr,"Number of else if Statements: %d\n",destination->function[i].number_of_else_if);
        fprintf(fptr,"Number of else Statements: %d\n",destination->function[i].number_of_else);
        fprintf(fptr,"Number of break Statements: %d\n",destination->function[i].number_of_break);
        fprintf(fptr,"Number of continue Statements: %d\n",destination->function[i].number_of_continue);
        fprintf(fptr,"Total Number of Lines: %d\n",destination->function[i].number_of_statements);
        fprintf(fptr,"\n");
    }
    fprintf(fptr,"\tProgram Details Continued...\n");
    fprintf(fptr,"Number of Lines: %d\n",destination->number_of_lines);
    fprintf(fptr,"Number of scanf Statements: %d\n",destination->number_of_scan);
    fprintf(fptr,"Number of printf Statements: %d\n",destination->number_of_print);
    fprintf(fptr,"Number of for loops: %d\n",destination->number_of_for);
    fprintf(fptr,"Number of while loops: %d\n",destination->number_of_while);
    fprintf(fptr,"Number of if Statements: %d\n",destination->number_of_if);
    fprintf(fptr,"Number of else Statements: %d\n",destination->number_of_else);
    fprintf(fptr,"Number of else if Statements: %d\n",destination->number_of_else_if);
    fprintf(fptr,"Number of break Statements: %d\n",destination->number_of_break);
    fprintf(fptr,"Number of int Variables: %d\n",destination->number_of_int);
    fprintf(fptr,"Number of float Variables: %d\n",destination->number_of_float);
    fprintf(fptr,"Number of char Variables: %d\n",destination->number_of_char);
    fprintf(fptr,"Number of long Variables: %d\n",destination->number_of_long);
    fprintf(fptr,"Number of double Variables: %d\n",destination->number_of_double);
    fprintf(fptr,"Number of bool Variables: %d\n",destination->number_of_bool);
    fprintf(fptr,"Number of Included Header Files: %d\n",destination->number_of_include);
    fprintf(fptr,"Number of #define pre-processors: %d\n",destination->number_of_define);
    fprintf(fptr,"Number of Structures: %d\n",destination->number_of_struct);
    fprintf(fptr,"Number of typedef: %d\n",destination->number_of_typedef);
    fprintf(fptr,"Number of void Functions: %d\n",destination->number_of_void_functions);
    fprintf(fptr,"Number of int Functions: %d\n",destination->number_of_int_functions);
    fprintf(fptr,"Number of float Functions: %d\n",destination->number_of_float_functions);
    fprintf(fptr,"Number of char Functions: %d\n",destination->number_of_char_functions);
    fprintf(fptr,"Number of bool Functions: %d\n",destination->number_of_bool_functions);
    fprintf(fptr,"Number of long Functions: %d\n",destination->number_of_long_functions);
    fprintf(fptr,"Number of double Functions: %d\n",destination->number_of_double_functions);
    fprintf(fptr,"\n\n\t\t\t\t*****End of Log*****");
    fclose(fptr);
    chdir("..");
    chdir("Files_to_be_checked");
    return true;
}

void display_introduction()
{
    FILE *fptr;
    fptr=fopen("Introduction.txt","r");
    char ch;
    clrscr();
    while(fscanf(fptr,"%c",&ch)!=EOF)
        printf("%c",ch);
    fclose(fptr);
    newline(2);
    tab(3);
    printf("Press any key to Continue...");
    raw_input();
}
void display_conclusion()
{
    FILE *fptr;
    fptr=fopen("Conclusion.txt","r");
    char ch;
    clrscr();
    while(fscanf(fptr,"%c",&ch)!=EOF)
        printf("%c",ch);
    fclose(fptr);
    newline(2);
    tab(3);
    printf("Press any key to Quit...");
    raw_input();
}
