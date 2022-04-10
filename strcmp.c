int _strcmp(char *s1, char *s2)
{
	int i, j;

i = 0;
j = 0;
while (s1[i] != '\0' || s2[i] != '\0')
{
	if (s1[i] != s2[i])
	{
		j = s1[i] - s2[i];
		break;
	}
	i++;
}
return (j);
}
