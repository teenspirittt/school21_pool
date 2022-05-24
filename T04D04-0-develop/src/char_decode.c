#include<stdio.h>
char reverse(char *str, int n) {
    for (int i = 0; i < n / 2; i++) {
        char t = str[i];
		str[i] = str[n - i - 1]; 
		str[n - i - 1] = t; 
	} 
	return *str;
}

char* converter(char *hex_number, int dec_number) { 
	int len = 0; 
    if (dec_number == 0)
		hex_number[0]=' ';
		else { 
			for (int i = 0; dec_number > 0; ++i, len = i) { 
				if (dec_number % 16 < 10) {
                    hex_number[i] = (dec_number % 16) + '0';
						} else { 
							hex_number[i] = (char) (dec_number % 16 + 55); 
						} 
			dec_number = dec_number / 16; 
			hex_number[i + 1] = '\0'; 
		} 
	} 
	reverse(hex_number, len);
   	
	return hex_number; 
}
void encoding() {
	char hex_number[20];
	char c = ' ';
	int num;
	int len = 0;
	while(c != '\n') {
		scanf("%c", &c);
		if(c == '\n')
			break;
		if(c == ' ')
			continue;
		num = c;
		converter(hex_number, num);
		printf("%s ", hex_number);
	}
}

void decoding() {
	char c = ' ';
	char c2 = ' ';
	int num;
	int num2;
	int final_num;
	int len= 0;
	int flag = 0;
	while(c != '\n') {
		if (flag == 0){
			if (c == '\n')
				break;
			if (c == ' ')
				continue;
			scanf("%c", &c);
			flag = 1;
			continue;
		} else if (flag == 1) {
				scanf("%c",&c2);
				if(c == '\n')
                    break;
				if(c == ' ')
					continue;
				flag = 0;
		}
		num = c;
		num2 = c2;
		final_num = num * 16;
		if (num2 < 10) {
            final_num = final_num + num2;
		} else {
			final_num = final_num + (num2 % 16) + 64;
			printf("%c ", final_num);
		}
	}
}

int main(int argc, char* argv[]) { 
	printf("aboba");

	return 0;
}

