#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int is_logged_in = 0;
char username[20];
char password[20];
char std_rollnum[7];
char course_code[5];

void load()
{
    int r,q;
    system("cls");
	system("color 0e");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t");
    printf("      loading...");
    printf("\n\n\t\t\t");
    for(r=1;r<=20;r++)
	{
    for(q=0;q<=5000000;q++);//to display the character slowly
    printf("%c",219);
	}
}

int login(char choice);
int attendance();			//	WHEN ATTENDANCE WILL BE MARKED OF A STUDENT
int marks();				//	WHEN MARKS WILL BE ADDED
int add_std();				//	ADMIN WILL HAVE ACCESS IN ORDER TO ADD A NEW STUDENT
int delete_std();			//	ADMIN WILL HAVE ACCESS IN ORDER TO REMOVE AN EXISTING STUDENT
int add_fac();				//	ADMIN WILL HAVE ACCESS IN ORDER TO ADD A NEW FACULTY
int delete_faculty();		//	ADMIN WILL HAVE ACCESS IN ORDER TO REMOVE AN EXISTING FACULTY
int ten_plan_CS();			//	A TENATIVE PLAN WILL BE SHOWN TO STUDENTS OF THEIR RESPECTIVE PROGRAM
int ten_plan_BBA();			
int ten_plan_EE();			//Tentative, login, store data, add student/faculty
int ten_plan_SE();			
int fees();					//
int course_registration();	//
int store_data();			// done

struct admin
{
	char admin_name[20];
	char admin_pass[20];
	char admin_mail[20];
}data_a;


								// DATA FOR STUDENTS
struct student
{
	char roll_num[7];			
	char names_std[20];			
	char std_dad[20];			// FOR MAX 20 CHARACTERS 
	char std_program[10];		
	char std_pass[20];			
	//struct student_marks distribution;
		
	int batch, range_program;	// roll number distributed
	char city_campus;			
    char campus[10],range[10];		
}data_s;

struct attend{
	char date[20];
	int duration;
	char aten;  //p or a
	char st_roll[8];
	char course_code[5];
}at_info;

struct course{
	char code[5];
	char course_rollno[7];
}reg;

								// DATA FOR FACULTY
struct faculty
{
	char fac_num[05];
	char fac_pass[20];
	char fac_name[20];			// FOR MAX 20 CHARACTERS 
	char category[20];			// WHAT EXACTLY IS BEING TAUGHT BY TEACHER USED FOR LOOKING FOR AVAILABLE TEACHER OF A RESPECTIVE COURSE
}data_f;

struct grade_of_course{
	float quiz, assignment, mid_1, mid_2, project, final, class_p;									//weitage
	float total_q, total_a, total_m1, total_m2, total_pro, total_f, total_cp;						//total marks
	float obtained_q, obtained_a, obtained_m1, obtained_m2, obtained_pro, obtained_f, obtained_cp;	//obtain marks
	char c_code[5];
	char grade_rollno[7];
	float total_obtained_marks;
	float w_q, w_a, W_m1, w_m2, w_pro, w_f, w_cp;
}grades;


								// MAIN FUNCTION
int main()
{

	
		int options;


		printf("Enter 1 for data input");
    	scanf("%d", &options);
    	if(options==1)
    	{
    		store_data();
		}
		login_page:
    	system("CLS");
    	load();
    	system("CLS");
    	
		char log;
		printf("Enter From The Following Options : \n"
			"A. Admin\nF. Faculty\nS. Student\n");
		scanf(" %c", &log);
		if(log>=97 && log <=123)
		log=(char)(log-32);

	switch(log)
		{
		case 'A':
			system("CLS");
			login(log);
			system("CLS");
			menu:
				system("CLS");
			printf("1. Add data\n2. Remove data\n3. Manage existing data\n4. Change password\n5. Back to Login Page\n");
			int select;
			
			scanf("%d", &select);
			int choice=0;
			switch(select)
			{
				case 1:   //add data
				    printf("To add faculty press 1 and to add student press 2:\n");
				    scanf("%d",&choice);
				    if(choice==1)
					{
				    add_fac();
					}
					else if(choice==2)
					{
					add_std();
					}
					getch();
					goto menu;
					
				break;
				case 2:   //remove data
					printf("To remove faculty press 1 and to add student press 2:\n");
				    scanf("%d",&choice);
				    if(choice==1)
					{
				    	delete_fac();
					}
					else if(choice==2)
					{
						delete_std();
					}
					goto menu;
				break; 
				case 3:   //Manage existing data
					goto menu;
				break;
				case 4:   //change password
				system("CLS");
					FILE *fp;
					fp=fopen("Admin.txt", "r+b");
					rewind(fp);
					while(fread(&data_a, sizeof(struct admin),1, fp )==1)
					{
						//	int a=1;
						if(strcmp(username,data_a.admin_name) == 0 &&  strcmp(password,data_a.admin_pass) ==0)
						{
							printf("Enter new password:\t");
							char new_pass[20];
							fflush(stdin);
							gets(new_pass);
							strcpy(data_a.admin_pass, new_pass);
							fseek(fp, ftell(fp) - sizeof(struct admin), 0);
							fwrite(&data_a, sizeof(struct admin),1, fp );
							printf("\nPassword Update !\n");
							fclose(fp);
							break;
						}
					
					}
					printf("admin change password section end");		
					goto menu;
				break;
				case 5:  //back to login
					goto login_page;
				break;
			}
		case 'F':
			system("CLS");
			login(log);	
			menu_f:
			system("CLS");
			printf("1. Attendance\n2. Add marks\n3. Remove marks\n4. Manage existing marks\n5. Change password\n6. Back to Login Page\n");
			int select1;
		
			scanf("%d", &select1);
			switch(select1)
			{
				case 1:
					attendance();
					goto menu_f;
					break;
				case 2:
					marks();
					goto menu_f;
					break;
				case 3:
					goto menu_f;
					break;
				case 4:
					 system("CLS");
				//		FILE *outfile;

    printf("Enter roll number of student to change his marks=");
  	fflush(stdin);
    gets(std_rollnum);
    printf("Enter your course code=");
  	fflush(stdin);
    gets(course_code);
    
		FILE *outfile=fopen("Student marks.txt", "r");
		fseek(outfile, 0, 0);

	while(fread(&grades, sizeof(struct grade_of_course), 1, outfile)==1 )
					{
			 printf("\n%s is roll number in file and %s is entered\n%s is course code in file and %s is course code entered" , grades.grade_rollno , std_rollnum , grades.c_code , course_code);
			
						if(strcmp(std_rollnum,grades.grade_rollno)== 0 &&  strcmp(course_code,grades.c_code)==0)
						{
							int update_mark;
							printf("\nEnter from the following options/marks to be updated:\n");
							printf("1. Quiz\n2. Assignment\n3. Mid 1\n4. Mid 2\n. 5. Final\n6. Project\n7. Class Participation");
							scanf("%d", &update_mark);
							switch(update_mark)
							{
								case 1:
									printf("Enter new quiz marks.");
									scanf("%f", &grades.w_q);
									break;
								
								case 2:
									printf("Enter new assignment marks.");
									scanf("%f", &grades.w_a);
									break;
								
								case 3:
									printf("Enter new mid 1 marks.");
									scanf("%f", &grades.W_m1);
									break;
								
								case 4:
									printf("Enter new mid 2 marks.");
									scanf("%f", &grades.w_m2);
									break;
								
								case 5:
									printf("Enter new final marks.");
									scanf("%f", &grades.w_f);
									break;
									
								case 6:
									printf("Enter new project marks.");
									scanf("%f", &grades.w_pro);
									break;
									
								case 7:
									printf("Enter new class participation marks.");
									scanf("%f", &grades.w_cp);
									break;
									
								default:
									printf("Wrong entry. Retry.");
									break;
							}
						}
						else
						{
							printf("\nData not found!");
						}
  	
  					}
  					
  					fseek(outfile, ftell(outfile) - sizeof(struct grade_of_course), 0);
  					fwrite(&grades, sizeof(struct grade_of_course), 1, outfile);
  					fclose(outfile);
  					getch();
					goto menu_f;
					break;
				case 5:
					system("CLS");
					FILE *fp;
					fp=fopen("Faculty data.txt", "r+b");
					rewind(fp);
					while(fread(&data_f, sizeof(struct faculty),1, fp )==1)
					{
						//	int a=1;
						if(strcmp(username,data_f.fac_name) == 0 &&  strcmp(password,data_f.fac_pass) ==0)
						{
							printf("Enter new password:\t");
							char new_pass[20];
							fflush(stdin);
							gets(new_pass);
							strcpy(data_f.fac_pass, new_pass);
							fseek(fp, ftell(fp) - sizeof(struct faculty), 0);
							fwrite(&data_f, sizeof(struct faculty),1, fp );
							printf("\nPassword Update !\n");
							fclose(fp);
							break;
						}
					
					}
					goto menu_f;
					break;
				case 6:
						goto login_page;
					break;
			}
			
			break;
		case 'S':
			system("CLS");
			login(log);
			menu_s:
			system("CLS");
			printf("1. Attendance\n2. Change password\n3. Register a course\n4. Calculate fees\n5. Show tentative plan\n6. Show marks\n7. Back to Login Page\n");
			int select2;

			scanf("%d", &select2);
			switch(select2)
			{
				case 1:   //Attendance
					system("CLS");
					FILE *att=fopen("attendence.txt", "r+b");
					if(att==NULL)
					{
						printf("Error opening file");
					}
					while(fread(&at_info, sizeof(struct attend), 1, att)==1)
					{
						if(strcmp(username, at_info.st_roll)==0)
						{
							system("CLS");
							fseek(att, ftell(att) - sizeof(struct attend), 0);
							printf("Roll Number :\t%s\nCourse :\t%s\nAttendance :\t%c\nDuration of lecture:\t%d\nDate of lecture: \t%s", at_info.st_roll, at_info.course_code, at_info.aten, at_info.duration, at_info.date);
			
						}
					}
						
					fclose(att);
				getch();
					goto menu_s;
				break;
				case 2:   //change password
					system("CLS");
					FILE *fp;
					fp=fopen("Student data.txt", "r+b");
					rewind(fp);
					while(fread(&data_s, sizeof(struct student),1, fp )==1)
					{
						//	int a=1;
						if(strcmp(username,data_s.roll_num) == 0 &&  strcmp(password,data_s.std_pass) ==0)
						{
							printf("Enter new password:\t");
							char new_pass[20];
							fflush(stdin);
							gets(new_pass);
							strcpy(data_s.std_pass, new_pass);
							fseek(fp, ftell(fp) - sizeof(struct student), 0);
							fwrite(&data_f, sizeof(struct student),1, fp );
							printf("\nPassword Update !\n");
							fclose(fp);
							break;
						}
					
					}
					goto menu_s;
				break; 
				case 3:   //register course
					course_registration();
					goto menu_s;
				break;
				case 4:   //fees
					fees();
					goto menu_s;
				break;
				
				case 5: //study plan
				
					system("CLS");
					if(data_s.range_program>=0 && data_s.range_program<400)
					ten_plan_BBA();
					else if(data_s.range_program>=400 && data_s.range_program<500)
					ten_plan_CS();
					else if(data_s.range_program>=800 && data_s.range_program<1000)
					ten_plan_EE();
					else if(data_s.range_program>=1200 && data_s.range_program<1500)
					ten_plan_SE();
				goto menu_s;
				break;
				case 6:		//show marks
					
					system("CLS");
					FILE *outfile=fopen("Student marks.txt", "r");
					while(fread(&grades, sizeof(struct grade_of_course), 1, outfile)==1 )
					{
						if(strcmp(username, grades.grade_rollno)==0)
						{
							printf("\t\tQuiz\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f", grades.total_q, grades.obtained_q, grades.quiz, grades.w_q);
							printf("\n\t\tAssignment\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f", grades.total_a, grades.obtained_a, grades.assignment, grades.w_a);
							printf("\n\t\tMid 1\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f", grades.total_m1, grades.obtained_m1, grades.mid_1, grades.W_m1);
							printf("\n\t\tMid 2\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f", grades.total_m2, grades.obtained_m2, grades.mid_2, grades.w_m2);
							printf("\n\t\tFinal\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f", grades.total_f, grades.obtained_f, grades.final, grades.w_f);
							printf("\n\t\tProject\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f", grades.total_pro, grades.obtained_pro, grades.project,grades.w_pro);
							printf("\n\t\tClass-P\n Total\t Obtained\t Weitage\t Obtained weitage\n");
							printf(" %f \t%f \t%f \t%f\n\nGrand Total:\t %f ", grades.total_cp, grades.obtained_cp, grades.class_p, grades.w_cp, grades.total_obtained_marks);
						
						}
					}
					getch();
					goto menu_s;
					break;
					
				case 7:  //back to login
						goto login_page;
				break;
			}
			
		}
}

int fees()
{
	int num,add=0,h=0,i;
	int fee,tax;
	char name[5];

	printf("enter the number of courses");
	scanf("%d",&num);
		for(i=1;i<=num;i++)
		{
			printf("enter the code of course you want to enroll ");
			scanf("%s",name);
			printf("enter credit hours for courses ");
			scanf("%d",&h);
			add=add+h;
		}
		
			fee=num*add*8000;
			printf("\n your total fee for register courses are %d",fee);
		if(fee<=80000)
		{
			tax=10000;
			fee=fee+tax;
			printf("\n your total fee including taxes are %d",fee);
		}
		else if(fee>80000 && fee<120000)
		{tax=12000;
			fee=fee+tax;
			printf("\n your total fee including taxes are %d",fee);
		}
		else if(fee>120000 && fee<=200000)
		{
			tax=16000;
			fee=fee+tax;
			printf("\n your total fee including taxes are %d",fee);
		}
	getch();
}

int student_login(char* username, char* password)
{
	FILE *fp = fopen("Student data.txt","r");
	int result = 0;
	while(fread(&data_s, sizeof(data_s), 1, fp)==1)
	{
		if(strcmp(username, data_s.roll_num) == 0 && strcmp(password, data_s.std_pass) ==0)
		{
			result = 1;
			break;
		}
	}
	fclose(fp);
	return result;
}


int attendance()
{
    struct student data_s;
	struct attend at_info;
	
	printf("Enter date in d/m/y form=");
    fflush(stdin);
    gets(at_info.date);
    fflush(stdin);
    printf("Enter course code=");
    fflush(stdin);
    gets(at_info.course_code);
	printf("\nEnter lecture duration");
	scanf("%d", &at_info.duration);
	FILE *outfile;
	FILE *infile;
    outfile=fopen("Student data.txt", "r");
    
	if(outfile==NULL)
	{
    	fprintf(stderr,"\nerror opening file.\n");
	}
    infile=fopen("attendence.txt", "a");
	int l=0;
	    while(fread(&data_s, sizeof(data_s), 1, outfile)==1)
		{
	       	strcpy(at_info.st_roll,data_s.roll_num);
			printf("For %s:\n",at_info.st_roll);
    		printf("Mark attendance:\n <A> absent \n <P> present\n");
    		scanf(" %c",&at_info.aten);
	    	fwrite(&at_info,sizeof (at_info),1,infile);
		}
			fclose(infile);
}
    
    


int admin_login(char* username, char* password)
{
	FILE *fp = fopen("Admin.txt","r");
	int result = 0;
	while(fread(&data_a, sizeof(data_a), 1, fp)==1)
	{
		if(strcmp(username, data_a.admin_name) == 0 && strcmp(password, data_a.admin_pass) == 0)
		{
			result = 1;
			break;
		}
	}
	fclose(fp);
	return result;
}

int faculty_login(char* username, char* password)
{
	FILE *fp = fopen("Faculty data.txt","r");
	int result = 0;
	while(fread(&data_f, sizeof(data_f), 1, fp)==1)
	{
		if(strcmp(username, data_f.fac_name) == 0 && strcmp(password, data_f.fac_pass) == 0)
		{
			result = 1;
			break;
		}
	}
	fclose(fp);
	return result;
}


int login(char choice)
{
    printf ("--------------------------------------------------------------------------------------\n");
    printf ("\t\t\t\t\tFLEX\n");
    printf ("\t\t\t\tWelcome to Login Page\n");
    printf ("--------------------------------------------------------------------------------------\n\n");

	int logged_in = 0;
	while(logged_in == 0) 
	{
		printf("Enter Login Identity:	");
		fflush(stdin);
		gets(username);
		
		printf("\nEnter Password:		");
		fflush(stdin);
		gets(password);

		switch(choice)
		{
			case 'A':
				logged_in = admin_login(username, password);
			break;
			case 'F':
				logged_in = faculty_login(username, password);
			break;
			case 'S':
				logged_in = student_login(username, password);
			break;
		}

		if(logged_in == 0)
		{
			printf("Failed to login, incorrect username and password\n\n");
		}
	}
	is_logged_in = logged_in;
}


int store_data()
{
				struct admin data_a;
				struct faculty data_f;
				struct student data_s;
	int i,n;
	char choice;
	printf("Enter the type of data you want to enter:\n");
			printf("Enter From The Following Options : \n"
			"A. Admin\nF. Faculty\nS. Student\n");
			scanf(" %c",&choice);
			if(choice>=97 && choice <=123)
		choice=(char)(choice-32);
	switch(choice)
	{
		case 'A':
		printf("\nEnter how much data of people you want to enter:\n");
		scanf("%d", &n);
	
		for(i=0;i<n;i++)
    	{
    	printf("\nEnter the Name   : ");
    	fflush(stdin);
		gets(data_a.admin_name);
		printf("\nEnter the email: ");
    	fflush(stdin);
    	gets(data_a.admin_mail);

    	printf("\nEnter the password: ");
    	fflush(stdin);
    	gets(data_a.admin_pass);

    	printf("This person has username %s \nand password %s\nand\n email is %s", data_a.admin_name,data_a.admin_pass,data_a.admin_mail );
		printf("\n\n %d\n\n", i+1);
		
    	FILE *outfile;

   		// open file for writing
    	outfile = fopen ("Admin.txt", "a");
    	if (outfile == NULL)
    	{
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    	}
    	// write struct to file
    	fwrite (&data_a, sizeof(struct admin), 1, outfile);
    	fclose(outfile);

    	if(fwrite != 0)
        printf("\ncontents to file written successfully !\n");
    	else
        printf("error writing file !\n");
		getch;
		}	break;
		
		case 'F':

		add_fac();
		
		case 'S':
		
		add_std();
	
	}
}
int add_fac()
{
	    int m=0,i; 
	    struct faculty data_f;
        printf("\nEnter how much data of people you want to add:\n");
		scanf("%d", &m);
	
		for(i=0;i<m;i++)
		{
    	printf("Enter the Name   : ");
    	fflush(stdin);
		gets(data_f.fac_name);
    	printf("\nEnter the employee number: ");
    	fflush(stdin);
		gets(data_f.fac_num);

    	printf("\nEnter the password: ");
    	fflush(stdin);
		gets(data_f.fac_pass);
		
		printf("\nEnter the category:	   ");
  		fflush(stdin);
		gets(data_f.category);
  	  	printf("This person has name %s \nand password %s\nand category %s\nandemployee number %s", data_f.fac_name,data_f.fac_pass,data_f.category,data_f.fac_num);

    	FILE *outfile;

   		// open file for writing
    	outfile = fopen ("Faculty data.txt", "a");
    	if (outfile == NULL)
    	{
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    	}
    	// write struct to file
    	fwrite (&data_f, sizeof(struct faculty), 1, outfile);
    	fclose(outfile);

    	if(fwrite != 0)
        printf("\ncontents to file written successfully !\n");
    	else
        printf("error writing file !\n");
        getch;
	}
}
int add_std()
{
	    int m=0,i; 
	    struct student data_s;
        printf("\nEnter how much data of people you want to add:\n");
		scanf("%d", &m);

		for(i=0;i<m;i++)	
			{
		printf("Enter the Student Name:	");
    	fflush(stdin);
		gets(data_s.names_std);
	
    	printf("\nEnter the roll number in respective manner:	\n1. Batch \n2. First Letter of City \n3. Ranging number with respect to Program\n");

    	scanf("%d", &data_s.batch);
		scanf(" %c", &data_s.city_campus);
		scanf("%d", &data_s.range_program);
		
		sprintf(data_s.roll_num, "%d", data_s.batch);
		sprintf(data_s.campus, "%c", data_s.city_campus);
		strcat(data_s.roll_num,data_s.campus);

		sprintf(data_s.range, "%d", data_s.range_program);
		strcat(data_s.roll_num, data_s.range);
		printf("Roll number is %s", data_s.roll_num);

		printf("\nEnter the password:	");
    	fflush(stdin);
		gets(data_s.std_pass);
		
		printf("\nEnter the name of Father or Guardian:	   ");
  		fflush(stdin);
		gets(data_s.std_dad);
  		
  		printf("\nEnter the program of student:		");
		fflush(stdin);
		gets(data_s.std_program);
  	  	printf("This person has name %s \nand password %s\nand program %s\nand roll number %s\nand %s is his/her father or guardian name", data_s.names_std,data_s.std_pass,data_s.std_program,data_s.roll_num,data_s.std_dad );

    	FILE *outfile;

   		// open file for writing
    	outfile = fopen ("Student data.txt", "a");
    	if (outfile == NULL)
    	{
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    	}
    	// write struct to file
    	fwrite (&data_s, sizeof(struct student), 1, outfile);
    	fclose(outfile);

    	if(fwrite != 0)
        printf("\ncontents to file written successfully !\n");
    	else
        printf("error writing file !\n");
		}
		
}
int delete_std()
{

		system("cls");	
		int count,flag=0;;
		char id[7];
		char findfaculty='a';
		char another='y';
		while(another=='y')
		{
			system("cls");

			printf("Enter the ID to  remove:\n");
			fflush(stdin);
			gets(id);
			
			FILE *fp,*ft;
			fp  =fopen("Student data.txt","r");
					ft=fopen("test.txt","w");
			while(fread(&data_s,sizeof(data_s),1,fp)==1)
			{
					if(strcmp(data_s.roll_num,id)!=0)
					{
					// findfaculty='t';		
					//	printf("Name and roll number %s and %s", data_s.names_std, data_s.roll_num);
						fwrite(&data_s,sizeof(data_s),1,ft);
					}
					else
					{
						flag=1;
					}
			}
			if(flag!=1)
			{
				printf("\nNot Found");
			//	return;
			}
			if(flag==1)
			{
				printf("\nRemoved");
			//	return;
			}
			
			fclose(fp);
			fclose(ft);
			remove("Student data.txt");
			rename("test.txt","Student data.txt");
			another=getch();
		}
	
}
int delete_fac()
{

	system("cls");	
		int count,flag=0;;
		char id[7];
		char findfaculty='a';
		char another='y';
		while(another=='y')
		{
			system("cls");

			printf("Enter the ID to  remove:\n");
			fflush(stdin);
			gets(id);
			
			FILE *fp,*ft;
			fp  =fopen("Faculty data.txt","r");
					ft=fopen("test.txt","w");
			while(fread(&data_f,sizeof(data_f),1,fp)==1)
			{
					if(strcmp(data_f.fac_name,id)!=0)
					{
					// findfaculty='t';		
						fwrite(&data_f,sizeof(data_f),1,ft);
					}
					else
					{
						flag=1;
					}
			}
			if(flag!=1)
			{
				printf("\nNot Found");
			fclose(fp);
			fclose(ft);
				return;
			}
			if(flag==1)
			{
				printf("\nRemoved");
			}
			
			fclose(fp);
			fclose(ft);
			remove("Faculty data.txt");
			rename("test.txt","Faculty data.txt");
			another=getch();
		}
	
}


int course_registration()
{
		if(data_s.range_program>=0 && data_s.range_program<400)
			ten_plan_BBA();
			else if(data_s.range_program>=400 && data_s.range_program<500)
			ten_plan_CS();
			else if(data_s.range_program>=800 && data_s.range_program<1000)
			ten_plan_EE();
			else if(data_s.range_program>=1200 && data_s.range_program<1500)
			ten_plan_SE();
	
		printf("\nWhich course do you want to register?\n");	
		char code[5];
		fflush(stdin);
		gets(reg.code);
			FILE *outfile;
	
	   		// open file for writing
	    	outfile = fopen ("Student courses.txt", "a");
	    	if (outfile == NULL)
	    	{
	        	fprintf(stderr, "\nError opend file\n");
	        	exit (1);
	    	}
	    	// write struct to file
	    	strcpy(reg.course_rollno, username);
	    	fwrite (&reg, sizeof(struct course), 1, outfile );
	    	fclose(outfile);
	
	    	if(fwrite != 0)
	        printf("\nCourse Registered Successfully\n");
	    	else
	        printf("Course Registration Failed!\n");  
}

int ten_plan_CS()
{
	printf("\nSEMESTER 01:\n");
	printf("COURSE CODE				COURSE TITLE					CrdHrs			Type");
	printf( "CL117		Intro to Info. and Comm. Technologies			1			Core\n"
			"CL118		Programming Fundamentals - Lab					1			Core\n"
			"CL217		Object Oriented Programming - Lab				1			Core\n"
			"CS118		Programming Fundamentals						3			Core\n"
			"EE117		Applied Physics									3			Core\n"
			"MT119		Calculus and Analytical Geometry				3			Core\n"
			"SL150		English Composition and Comprehension - Lab		1			Core\n"
			"SS113		Pakistan Studies								3			Core\n"
			"SS150		English Composition and Comprehension			2			Core\n");

	printf("\nSEMESTER 02:\n");
	printf("COURSE CODE				COURSE TITLE					CrdHrs			Type\n");
	printf( "CL217		Object Oriented Programming - Lab				1			Core\n"
			"CS217		Object Oriented Programming						3			Core\n"
			"EE227		Digital Logic Design							3			Core\n"
			"EL227		Digital Logic Design - Lab						1			Core\n"
			"MT224		Differential Equations (Cal II)					3			Core\n"
			"SL152		Communication & Presentation Skills - Lab		1			Core\n"
			"SS111		Islamic and Religious Studies					3			Core\n"
			"SS114		Human Ethics and Behavior						3			Core\n"
			"SS118		Psychology										3		Elective\n"
			"SS127		Sociology										3		Elective\n"
			"SS152		Communication & Presentation Skills				2			Core\n");
	
	printf("\nSEMESTER 03:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL218		Data Structures - Lab							1			Core\n"
			"CS211		Discrete Structures								3			Core\n"
			"CS218		Data Structures									3			Core\n"
			"MT104		Linear Algebra									3			Core\n");

	printf("\nSEMESTER 04:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL219		Database Systems - Lab							1			Core\n"
			"CL220		Operating Systems - Lab							1			Core\n"
			"CS219		Database Systems								3			Core\n"
			"CS220		Operating Systems								3			Core\n"
			"CS302		Design and Analysis of Algorithms				3			Core\n"
			"EE229		Comp. Organization and Assembly Lang			3			Core\n"
			"EL229		Comp. Organization and Assembly Lang-Lab		1			Core\n"
			"MT206		Probability and Statistics						4			Core");

	printf("\nSEMESTER 05:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf("CL307		Computer Networks Lab							1			Core\n"
			"CS301		Theory of Automata								3			Core\n"
			"CS307		Computer Networks								3			Core\n"
			"CS324		Software Design and Analysis					3			Core\n"
			"CS325		Numerical Computing								3			Core\n"
			"SS142		Technical Report Writing						3			Core\n");

	printf("\nSEMESTER 06:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf("CS326		Parallel and Distributed Computing				3			Core\n"
			"CS328		Software Engineering							3			Core\n"
			"CS461		Artificial Intelligence							3			Core\n");
	
	printf("\nSEMESTER 07:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf(	"CS462		Information Security							3			Core\n"
			"CS463		Professional Practices							3			Core\n"
			"CS491		Project - I										3			Core\n");
	
	printf("\nSEMESTER 08:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf("CS492		Project - II									3			Core\n");

getch();
}
int ten_plan_BBA()
{
	printf("\nSEMESTER 01:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL114		IT in Business - Lab							1			Core\n"
			"CS114		IT in Business									2			Core\n"
			"MG108		Fundamentals of Accounting						3			Core\n"
			"MT111		Business Math - I								3			Core\n"
			"SL149		English I - Lab									1			Core\n"
			"SS127		Sociology										3			Core\n"
			"SS149		English I										3			Core\n"
			"SS229		Psychology										2			Core\n");

	printf("\nSEMESTER 02:\n");	
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "MG224		Financial Accounting							3			Core\n"
			"ML224		Financial Accounting - Lab						1			Core\n"
			"MT118		Business Statistics								3			Core\n"
			"SL225		English II - Lab								1			Core\n"
			"SS111		Islamic and Religious Studies					3			Core\n"
			"SS118		Psychology										3			Core\n"
			"SS225		English - II									3			Core\n");

	printf("\nSEMESTER 03:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");	
	printf("MG220		Marketing Management							3			Core\n"
			"MG223		Fundamentals of Management						3			Core\n"
			"MG331		Management Accounting							3			Core\n"
			"ML216		Statistical Inference - Lab						1			Core\n"
			"MT216		Statistical Inference							3			Core\n"
			"SS223		Business Communication - I						3			Core\n");

	printf("\nSEMESTER 04:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "MG225		Organizational Behavior							3			Core\n"
			"MG228		Business Finance								3			Core\n"
			"MG309		Consumer Behavior								3			Core\n"
			"MT223		Business Math - II								3			Core\n"
			"SS135		Micro Economics									3			Core\n");

	printf("\nSEMESTER 05:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "MG311		Financial Management							3			Core\n"
			"MG320		Operations Management							3			Core\n"
			"MG333		Human Resource Management						3			Core\n"
			"ML311		Financial Management - Lab						1			Core\n"
			"SS131		Macro Economics									3			Core\n");

	printf("\nSEMESTER 06:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL310		Management Info. Systems - Lab					1			Core\n"
			"CS310		Management Info. Systems						3			Core\n"
			"MG302		Business Law									3			Core\n"
			"MG305		Methods in Business Research					3			Core\n"
			"MG312		Financial Institutions and Markets				3			Core\n"
			"MG314		Financial Statement Analysis					3			Core\n"
			"MG414		Entrepreneurship								3			Core\n"
			"ML305		Methods in Business Research - Lab				1			Core\n"
			"SS309		Business Communication - II						3			Core\n");

	printf("\nSEMESTER 07:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf("MG402S		trategic Management								3			Core\n"
			"MG404		Economy of Pakistan								3			Core\n"
			"MG440		Final Year Project - I							3			Core\n"
			"SS113		Pakistan Studies								3			Core\n"
			"SS138		History of Pakistan								3			Core\n");

	printf("\nSEMESTER 08:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "MG324		Business Ethics									3			Core\n"
			"MG414		Entrepreneurship								3			Core\n"
			"MG419		Final Year Project - II							3			Core\n");
getch();
}

int ten_plan_EE()			
{
	printf("\nSEMESTER 01:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "EE116		Introduction to Computing						2			Core\n"
			"EE211		Engineering Workshop							1			Core\n"
			"EL116		Introduction to Computing - Lab					1			Core\n"
			"MT117		Applied Calculus								3			Core\n"
			"NL110		Physics for Engineers Lab						1			Core\n"
			"NS110		Physics for Engineers							3			Core\n"
			"SS101		English Language								3			Core\n"
			"SS113		Pakistan Studies								3			Core\n");

	printf("\nSEMESTER 02:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");	
	printf( "CL214		Programming Fundamentals - Lab					1			Core\n"
			"CS210		Data Structures and Algorithms					3			Core\n"
			"CS214		Programming Fundamentals						3			Core\n"
			"EE115		Linear Circuit Analysis							3			Core\n"
			"EE228		Electrical Network Analysis						3			Core\n"
			"EL115		Linear Circuit Analysis - Lab					1			Core\n"
			"ME102		Engineering Drawing								1			Core\n"
			"MT203		Differential Equations							3			Core\n"
			"SS111		Islamic and Religious Studies					3			Core\n");	

	printf("\nSEMESTER 03:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL210		Data Structures and Algorithms - Lab			1			Core\n"
			"CS210		Data Structures and Algorithms					3			Core\n"
			"EE225		Electronic Devices and Circuits					3			Core\n"
			"EE228		Electrical Network Analysis						3			Core\n"
			"EL225		Electronic Devices and Circuits - Lab			1			Core\n"
			"EL228		Electrical Network Analysis Lab					1			Core\n"
			"MT104		Linear Algebra									3			Core\n");

	printf("\nSEMESTER 04:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");	
	printf( "EE223		Signals and Systems								3			Core\n"
			"EE224		Electronic Circuit Design						3			Core\n"
			"EE227		Digital Logic Design							3			Core\n"
			"EE319		Probability and Random Processes				3			Core\n"
			"EL223		Signals and Systems Lab							1			Core\n"
			"EL224		Electronic Circuit Design Lab					1			Core\n"
			"EL227		Digital Logic Design - Lab						1			Core\n"
			"MT306		Multivariable Calculus							3			Core\n");

	printf("\nSEMESTER 05:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "EE221		Electro Mechanical Systems						3			Core\n"
			"EE303		µP Interfacing and Programming					3			Core\n"
			"EE305		Electromagnetic Theory							3			Core\n"
			"EE323		Analogue and Digital Communication				3			Core\n"
			"EE431		Power System Analysis							3			Core\n"
			"EL221		Electro Mechanical Systems Lab					1			Core\n"
			"EL224		Electronic Circuit Design Lab					1			Core\n"
			"EL303		µP Interfacing and Programming Lab				1			Core\n"
			"EL323		Analogue and Digital Communication - Lab		1			Core\n"
			"EL324		Power Electronics - Lab							1			Core\n"
			"EL431		Power System Analysis - Lab						1			Core\n"
			"MT220		Complex Variables and Transforms				3			Core\n");

	printf("\nSEMESTER 06:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "EE224		Electronic Circuit Design						3			Core\n"
			"EE224		Electronic Circuit Design						3			Core\n"
			"EE304		Feedback Control Systems						3			Core\n"
			"EE324		Power Electronics								3			Core\n"
			"EL215		Comp. Organization and Architecture Lab			1			Core\n"
			"EL224		Electronic Circuit Design Lab					1			Core\n"
			"EL224		Electronic Circuit Design Lab					1			Core\n"
			"EL304		Feedback Control Systems Lab					1			Core\n"
			"EL324		Power Electronics - Lab							1			Core\n"
			"MG222		Engineering Economics							3			Core\n"
			"SS123		Communication Skills							3			Core\n"
			"SS142		Technical Report Writing						3			Core\n");
	
	printf("\nSEMESTER 07:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "EE224		Electronic Circuit Design						3			Core\n"
			"EE482		Project - I										3			Core\n"
			"EL224		Electronic Circuit Design Lab					1			Core\n"
			"MG414		Entrepreneurship								3			Core\n"
			"SS123		Communication Skills							3			Core\n");
	
	printf("\nSEMESTER 08:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "EE224		Electronic Circuit Design						3			Core\n"
			"EE324		Power Electronics								3			Core\n"
			"EE483		Project - II									3			Core\n"
			"EL224		Electronic Circuit Design Lab					1			Core\n"
			"EL324		Power Electronics - Lab							1			Core\n"
			"MG205		Entrepreneurship								3			Core\n"
			"MG330		Engineering Management							3			Core\n");

getch();
}
int ten_plan_SE()
{
	printf("\nSEMESTER 01:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			 Type\n");
	printf( "CL117		Intro to Info. and Comm. Technologies			1			 Core\n"
			"CL118		Programming Fundamentals - Lab					1			 Core\n"
			"CS118		Programming Fundamentals						3			 Core\n"
			"EE117		Applied Physics									3	         Core\n"
			"MT119		Calculus and Analytical Geometry				3			 Core\n"
			"SL150		English Composition and Comprehension - Lab		1			 Core\n"
			"SS113		Pakistan Studies								3			 Core\n"
			"SS150		English Composition and Comprehension			2		 	 Core\n");
	
	printf("\nSEMESTER 02:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL217		Object Oriented Programming - Lab				1			Core\n"
			 "CS211		Discrete Structures								3			Core\n"
			 "CS217		Object Oriented Programming						3			Core\n"
			 "SE110		Intro to Software Engineering					3			Core\n"
			 "SL152		Communication & Presentation Skills - Lab		1			Core\n"
			 "SS111		Islamic and Religious Studies					3			Core\n"
			 "SS114		Human Ethics and Behavior						3			Core\n"
			 "SS152		Communication & Presentation Skills				2			Core\n");
	
	printf("\nSEMESTER 03:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf(	"CL218		Data Structures - Lab							1			Core\n"
			"CS218		Data Structures									3			Core\n"
			"CS422		Human Computer Interaction						3			Core\n"
			"MT104		Linear Algebra									3			Core\n"
			"SE210		Software Requirement Engineering				3			Core\n");
	
	printf("\nSEMESTER 04:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL219		Database Systems - Lab							1			Core\n"
			"CL220		Operating Systems - Lab							1			Core\n"
			"CS219		Database Systems								3			Core\n"
			"CS220		Operating Systems								3			Core\n"
			"SE220		Software Design and Architecture				2			Core\n"
			"SL220		Software Design and Architecture - Lab			1			Core\n");
	
	printf("\nSEMESTER 05:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CL307		Computer Networks Lab							1			Core\n"
			"CS307		Computer Networks								3			Core\n"
			"MT205		Probability and Statistics						3			Core\n"
			"SE310		Software Construction and Development			2			Core\n"
			"SL310		Software Construction and Development - Lab		1			Core\n"
			"SS153		Technical and Business Writing					3			Core\n");
	
	printf("\nSEMESTER 06:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CS463		Professional Practices							3			Core\n"
			"SE321		Software Quality Engineering					3			Core\n"
			"SE322		Web Engineering									3			Core\n");
	
	printf("\nSEMESTER 07:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "CS462		Information Security							3			Core\n"
			"CS517		Software Project Management						3			Core\n"
			"SE491		Final Year Project - I							3			Core\n");
	
	printf("\nSEMESTER 08:\n");
	printf("COURSE CODE			COURSE TITLE						CrdHrs			Type\n");
	printf( "SE410		Software Re-Engineering							3			Core\n"
			"SE492		Final Year Project - II							3			Core\n");
getch();
}

int marks()
{

	int wc=0,oc=0;																					//check
	int which_marks, i=0;

	
		FILE *fp, *mark_file;
		fp=fopen("student courses.txt","r+b");
		mark_file=fopen("Student marks.txt", "a+");
		
		printf("Enter course code=");
		fflush(stdin);
		gets(grades.c_code);
		
		while(fread(&reg, sizeof(struct course), 1, fp)==1)
		{
			printf("Enter the Roll Number of student:");
			fflush(stdin);
			gets(grades.grade_rollno);
	
			if(strcmp(reg.course_rollno,grades.grade_rollno)==0  &&  strcmp(reg.code,grades.c_code)==0)	
			{
				printf("You are entering students marks:)\n press 1 to enter marks of Quiz.\n press 2 to enter marks of assignment.\n press 3 to enter marks of Mid1.");
				printf("\n press 4 to enter marks of mid2.\n press 5 to enter marks of Project.\n press 6 to enter marks of Final.\n press 7 to enter marks of Class participation.");
				scanf("%d",&which_marks);
				
				int weitage=0;
						// for mid1 and 2 10, for project 10 ,final 50
						// cp can be >0 and 5 ,quiz >0 and <10 ass>0 & <10
			
															switch(which_marks)
			{
			case 1:    //quiz
			
			printf("Enter total_q marks=");
			scanf("%f",&grades.total_q);
				while(oc!=1)
				{						// already entered - weitage = available weightage of quiz
					printf("Enter weitage(1-10)");
					scanf("%f",&grades.quiz);
					if(grades.quiz<=10 && grades.quiz>=0)
						{				// course total_q hga = quiz + assignment+ mids + final + project + cp weightage if (==100)	
						oc=1;
						
						while(wc!=1)
							{
								fflush(stdin);
								printf("\nEnter obtain marks(total_q>obtain) of student %s=",grades.grade_rollno);
								scanf("%f",&grades.obtained_q);
							if(grades.total_q>grades.obtained_q)
								{
									grades.w_q=(grades.obtained_q/grades.total_q)*grades.quiz;
								printf("\nMarks=%f out of %f",grades.w_q,grades.quiz);
								wc=1;
								}
							else
								{
								wc=0;
								}
							}
						
						}
					else
						{
						oc=0;
						}
				}
			oc=1;
			wc=1;
	break;
	
			case 2:    //assignment
	printf("Enter total_a marks=");
	scanf("%f",&grades.total_a);
	
	while(oc!=1)
	{
		printf("Enter assignment(1-10)");
		scanf("%f",&grades.assignment);
		if(grades.assignment<=10 && grades.assignment>=0)
		{
			oc=1;
		while(wc!=1)
			{
				
					fflush(stdin);
					printf("\nEnter obtain marks(total_a>obtain) of student %s=",grades.grade_rollno);
					scanf("%f",&grades.obtained_a);
					fflush(stdin);
					
					if(grades.total_a>grades.obtained_a)
						{
							grades.w_a=(grades.obtained_a/grades.total_a)*grades.assignment;
						printf("\nMarks=%f out of %f",grades.w_a,grades.assignment);
						wc=1;
						}
					else
						{
						wc=0;
						}
					
				
			}
		
		}
		else
		{
			oc=0;
		}
	}
	oc=1;
	wc=1;
	break;

				case 3:    //mid 1
	grades.mid_1=10;
	printf("Enter total_m1 marks=");
	scanf("%f",&grades.total_m1);
	while(wc!=1)
		{
			
				fflush(stdin);
				printf("\nEnter obtain marks(total_m1>obtain) of student %s=",grades.grade_rollno);
				scanf("%f",&grades.obtained_m1);
				fflush(stdin);
			
				if(grades.total_m1>grades.obtained_m1)
				{
					grades.W_m1=(grades.obtained_m1/grades.total_m1)*grades.mid_1;
					printf("\nMarks=%f out of %f",grades.W_m1,grades.mid_1);
					wc=1;
				}
				else
				{
					wc=0;
				}
		}
		oc=1;
		wc=1;
		break;
		
					case 4:    //mid2
		grades.mid_2=10;
		printf("Enter total_m2 marks=");
		scanf("%f",&grades.total_m2);
		while(wc!=1)
		{
		
				fflush(stdin);
				printf("\nEnter obtain marks(total_m2>obtain) of student %s=",grades.grade_rollno);
				scanf("%f",&grades.obtained_m2);
				fflush(stdin);
				
				if(grades.total_m2>grades.obtained_m2)
				{
					grades.w_m2=(grades.obtained_m2/grades.total_m2)*grades.mid_2;
					printf("\nMarks=%f out of %f",grades.w_m2,grades.mid_2);
					wc=1;
				}
				else
				{
					wc=0;
				}
		
			
		}
	oc=1;
	wc=1;
	break;
	
				case 5:       //project
	grades.project=10;
	printf("Enter total_pro marks=");
	scanf("%f",&grades.total_pro);
	while(wc!=1)
	{
			fflush(stdin);
			printf("\nEnter obtain marks(total_pro>obtain) of student %s=",grades.grade_rollno);
			scanf("%f",&grades.obtained_pro);
			fflush(stdin);
		
			if(grades.total_pro>grades.obtained_pro)
			{
				grades.w_pro=(grades.obtained_pro/grades.total_pro)*grades.project;
				printf("\nMarks=%f out of %f",grades.w_pro,grades.project);
				wc=1;
			}
			else
			{
				wc=0;
			}
	
		
	}
	oc=1;
	wc=1;
	break;  
	
				case 6:            //final
	grades.final=50;
    printf("Enter total_f marks=");
	scanf("%f",&grades.total_f);
	while(wc!=1)
	{
			fflush(stdin);
			printf("\nEnter obtain marks(total_f>obtain) of student %s=",grades.grade_rollno);
			scanf("%f",&grades.obtained_f);
			fflush(stdin);
		
			if(grades.total_f>grades.obtained_f)
			{
				grades.w_f=(grades.obtained_f/grades.total_f)*grades.final;
				printf("\nMarks=%f out of %f",grades.w_f,grades.final);
				wc=1;
			}
			else
			{
				wc=0;
			}

		
	}
	oc=1;
	wc=1;
	break;
	
				case 7:       //class participation
	printf("Enter total_cp marks=");
	scanf("%f",&grades.total_cp);
	while(oc!=1)
	{
		printf("Enter class_p(1-5)");
		scanf("%f",&grades.class_p);
		if(grades.class_p<=5 && grades.class_p>=0)
			{
				oc=1;
			while(wc!=1)
				{

						fflush(stdin);
						printf("\nEnter obtain marks(total_cp>obtain) of student %s=",grades.grade_rollno);
						scanf("%f",&grades.obtained_cp);
						fflush(stdin);
						
						if(grades.total_cp>grades.obtained_cp)
						{
							grades.w_cp=(grades.obtained_cp/grades.total_cp)*grades.class_p;
							printf("\nMarks=%f out of %f",grades.w_cp,grades.class_p);
							wc=1;
						}
						else
						{
							wc=0;
						}
			
				}
			}
		else
		{
			oc=0;
		}
	}
	oc=1;
	wc=1;
	break;
	}
		grades.total_obtained_marks = grades.w_a + grades.w_cp + grades.w_f + grades.W_m1 + grades.w_m2 + grades.w_pro + grades.w_q;
		printf("\n\n\t\tTotal obtained marks are: %f", grades.total_obtained_marks);
			fwrite(&grades, sizeof(struct grade_of_course), 1, mark_file);
			}
			else
			{
				printf("\nStudent OR Course not registered\nTry again");
			//	fseek(mark_file, ftell(mark_file)- sizeof(struct grade_of_course), 0);
			}
			
		}
		fclose(fp);
		fclose(mark_file);
		getch();
}
