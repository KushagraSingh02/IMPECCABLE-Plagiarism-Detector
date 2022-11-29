int main()
{
    clrscr();
    display_introduction();
    bool flag=true;
    int number_of_files;
    chdir("Files_to_be_checked");
    char name_of_file[100];
    while(flag)
    {
        clrscr();
        newline(3);
        tab(4);
        printf("This Application detects Plagiarism among Set of Programming Codes");
        newline(2);
        tab(4);
        printf("Choose a file to search for Plagiarised Content among others");
        number_of_files=display_files(".");
        printf("Enter the name of the File to be checked:\t");
        scanf("%s",name_of_file);
        char trash;
        scanf("%c",&trash);
        report_plagiarism(name_of_file,number_of_files);
        flag=prompt_continue();
    }
    chdir("..");
    display_conclusion();
    return 0;
}
