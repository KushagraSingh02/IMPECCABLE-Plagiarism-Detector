void strlwr(char *string)
{
    for(int i=0;i<strlen(string);i++)
        string[i]=tolower(string[i]);
}