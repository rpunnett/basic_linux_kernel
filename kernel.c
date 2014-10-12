/*
* kernal.c
*/

void kmain(void)
{
	char *str = "This is a beginners kernel"; //String to print to screen
	char *vidptr = (char*)0xb8000; //video memory begins here
	unsigned int i = 0;
	unsigned int j = 0;
	//CLEAR
	while(j < 80 * 25 * 2) {
		//Empty
		vidptr[j] = ' ';
		//Attribute-byte: white
		vidptr[j+1] = 0x0f; 
		j = j + 2;
	}
	j = 0;
	while(str[j] != '\0') {
		vidptr[i] = str[j];
		vidptr[i+1] = 0x1f;
		++j;
		i = i + 2;
	}
	return;
}
