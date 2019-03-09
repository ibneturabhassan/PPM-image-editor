
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

////functions for effects on ppm image////
void high_contrast(); 
void negate_red();
void negate_green(); 
void negate_blue();
void flatten_red();
void flatten_green();
void flatten_blue();
void greyscale_luminos();
void black_and_white_contrast();
void noise();
void blurr();
void choice();
void input_data();
void fprint_header();

FILE *fp;//creating pointer for file
FILE *fpw;//pointer for writing file
char input[200];//name of input file
char output[200];//name of output file
char hd[3];//magic number in the header of file

int rw = 0;//total rows in input file
int cl = 0;//total columns in input file
int cr = 0;//colour range in imaage
int array[10][3];//for storing numbers which make image
int i = 0;//for rows
int j = 0;//for columns
int k = 0;//for red,green,blue columns
int select;//for choosing effect


////MAIN function////
int main()
{
	char option;
	do
	{
		input_data();
		fp = fopen(input, "r");//to open file
		//check if file exists otherwise display error
		if (fp == NULL) {
			printf("\n\tERROR!!\tfile does not exist!\n");
			return 0;
		}
		fscanf(fp, "%s", hd);//magic number
		fscanf(fp, "%d", &rw);//row size
		fscanf(fp, "%d", &cl);//column size
		fscanf(fp, "%d", &cr);//color range

		fpw = fopen(output, "w");//opening file for editing
		system("cls");
		choice();//function call
		fclose(fp);
		fclose(fpw);


		printf("Press 0 to exit or press any key to continue: ");
		option = getche();

		fp = "NULL";
		fpw = "NULL";
	} while (option != '0');

	printf("\n\t\t\t\t\t\t\t\t\tTHANKYOU FOR USING THE SYSTEM!\n");
	system("pause");
	getch();
	//return 0;
}

void input_data()//taking names of input and output file
{
	system("cls");
	printf("\n\t\t\t\t\t\t\t\t\tWELCOME\n");
	printf("_______________________________________________________________________________________________________________________________________________________________________");
	printf("\n\t\t\t\t\t\t\t\"Portable Pixmap (PPM) Image Editor\"\n\n");
	printf("_______________________________________________________________________________________________________________________________________________________________________");
	printf("\n These are the images available:");
	printf("\n 1.cake.ppm\n\n 2.tinypix.ppm\n\n");
	//printf("\n______________________________________________________________________________________________________________________________________________________________________");
	printf("\nEnter name or path of ppm image file: ");

	_flushall();

	gets(input);
	printf("\nEnter name of output file: ");



	gets(output);
}

void fprint_header()//header of ppm image
{
	fprintf(fpw, "%s\n", hd);
	fprintf(fpw, "  %d", rw);
	fprintf(fpw, " %d\n", cl);
	fprintf(fpw, "  %d\n", cr);
}
void choice()//displaying menu for choice
{
	printf("\n________________________________________________________________________________________________________________________________________________________________________");
	printf("\n\t\t\t\t\t\t\t\t\tMAIN MENU\t\t\t");
	printf("\n________________________________________________________________________________________________________________________________________________________________________");
	printf("\n \t\t\t\t\t\t\t\t1:\tHIGH CONTRAST\t ");
	printf("\n\t\t\t\t\t\t\t\t2:\tNEGATE_RED\t");
	printf("\n\t\t\t\t\t\t\t\t3:\tNEGATE_GREEN\t");
	printf("\n\t\t\t\t\t\t\t\t4:\tNEGATE_BLUE\t");
	printf("\n\t\t\t\t\t\t\t\t5:\tLUMINOUS_GREY_SCALE\t");
	printf("\n\t\t\t\t\t\t\t\t6:\tFLATTEN_RED\t");
	printf("\n\t\t\t\t\t\t\t\t7:\tFLATTEN_GREEN\t");
	printf("\n\t\t\t\t\t\t\t\t8:\tFLATTEN_BLUE\t");
	printf("\n\t\t\t\t\t\t\t\t9:\tHIGH_CONTRAST_BLACK\t");
	printf("\n\t\t\t\t\t\t\t\t10:\tRandom_Noise\t");
	printf("\n\t\t\t\t\t\t\t\t11:\tBlurr\t");
	
	printf("\n____________________________________________________________________________________________________________________________________________________________________");
	printf("\n\nENTER YOUR CHOICE:");
	scanf_s("%d", &select);
	printf("\n\t\t\t\t\t\t\t\t\t PLEASE WAIT...PROCESSING...\n");
	switch (select)
	{
	case 1:
		high_contrast();
		break;
	case 2:
		negate_red();
		break;
	case 3:
		negate_green();
		break;
	case 4:
		negate_blue();
		break;
	case 5:
		greyscale_luminos();
		break;
	case 6:
		flatten_red();
		break;
	case 7:
		flatten_green();
		break;
	case 8:
		flatten_blue();
		break;
	case 9:
		black_and_white_contrast();
		break;
	case 10:
		noise();
		break;
	case 11:
		blurr();
		break;
	default:
		printf("YOU DIDNOT ENTER CORRECT CHOICE\n");
	}
}
///////////////functions for effects on image////////////////////
void greyscale_luminos()
{
	fprint_header();//function call
	int avg, sum = 0, r = 0, g = 0, b = 0;
	for (i = 0; i < rw; i++)
	{
		for (j = 0; j < cl; j++)
		{
			for (k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 0)
				{
					r = 0.21*array[j][k];
				}
				if (k == 1)
				{
					g = 0.72*array[j][k];
				}
				if (k == 2)
				{
					b = 0.07*array[j][k];
				}
				sum = sum + r + g + b;
			}
			avg = sum / 3;
			for (int k = 0; k < 3; k++)//R,G,B
			{

				fprintf(fpw, "  %d", avg);
				//printf("  %d", pix);
			}
			sum = avg = 0;

		}
		fprintf(fpw, "\n");
	}
}

void negate_red()//function definition for negating red pixels
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 0)
				{
					array[j][k] = -array[j][k];
				}
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}
void negate_green()//function definition for negating green pixels
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 1)
				{
					array[j][k] = -array[j][k];
				}
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}
void negate_blue()//function definition for negating blue pixels
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 2)
				{
					array[j][k] = -array[j][k];
				}
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}
void flatten_red()//function definition for flattening red pixels
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 0)
				{
					array[j][k] = 0;
				}
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}

void flatten_green()//function definition for flattening green pixels
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 1)
				{
					array[j][k] = 0;
				}
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}
void flatten_blue()//function definition for flattening blue pixels
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (k == 2)
				{
					array[j][k] = 0;
				}
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}
void high_contrast() //function definition for brightning image
{
	fprint_header();//function call
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (array[j][k] > 128)
					array[j][k] = 255;
				else
					array[j][k] = 0;

				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}
void black_and_white_contrast() //function definition to black and white image
{
	fprint_header();//function call
	int avg, sum = 0, r = 0, g = 0, b = 0;
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				if (array[j][k] > 128)
					array[j][k] = 255;
				else
					array[j][k] = 0;
				if (k == 0)
				{
					r = 0.21*array[j][k];
				}
				if (k == 1)
				{
					g = 0.72*array[j][k];
				}
				if (k == 2)
				{
					b = 0.07*array[j][k];
				}
				sum = sum + r + g + b;
			}
			avg = sum / 3;
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fprintf(fpw, "  %d", avg);
			}
			sum = avg = 0;
		}
		fprintf(fpw, "\n");
	}
}
void noise() //function definition for random noise
{
	fprint_header();//function call
	float a = 0.25;
	float rnoise, range = 2 * a;
	srand(time(NULL));
	for (int i = 0; i < rw; i++)
	{
		for (int j = 0; j < cl; j++)
		{
			for (int k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
				rnoise = rand()*range - a;
				rnoise = rnoise / 10000;
				array[j][k] *= (int)rnoise;
				fprintf(fpw, "  %d", array[j][k]);
			}
		}
		fprintf(fpw, "\n");
	}
}

void blurr() //function definition to blurr image
{
	fprint_header();//function call
	int r = 0, b = 0, g = 0, i = 0, j = 0, k = 0;
	for (i = 0; i < rw; i++)
	{
		for (j = 0; j < cl; j++)
		{
			r = 0, g = 0, b = 0;
			for (k = 0; k < 3; k++)//R,G,B
			{
				fscanf(fp, "%d", &array[j][k]);
			}
		}

		for (j = 0; j < cl; j++)
		{
			for (k = 0; k < 3; k++)
			{

				if (k == 0)
				{
					r = (array[j + 1][k] + array[j - 1][k] + array[j][k]) / 3;

					fprintf(fpw, "%d ", r);
				}
				else if (k == 1)
				{
					g = (array[j + 1][k] + array[j - 1][k] + array[j][k]) / 3;
					fprintf(fpw, "%d ", g);
				}
				else if (k == 2)
				{
					b = (array[j + 1][k] + array[j - 1][k] + array[j][k]) / 3;
					fprintf(fpw, "%d ", b);
				}

			}

		}

		fprintf(fpw, "\n");
	}

}

