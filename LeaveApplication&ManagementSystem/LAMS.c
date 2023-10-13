#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct staff{
        char fname[50];
        char lname[50];
        int staff_id;
        char dpt[50];
        char rfl[1000];
        int sd;
        int sm;
        int ed;
        int em;
        int dl_d;
        int dl_m;
    };


    struct staff_data{

        char fname[50];
        char lname[50];
        int staff_id;
        char dpt[50];
        char email[100];
        int al;
        int cl;
        int el;
        int matl;
        int medl;

    }; 

    struct staff_lar{

        int sid;
        char dpt[50];
        char ar[20];
        char rfl[50];
        int dl_d;
        int dl_m;

    };



void search_leave() {

    struct staff_data sd;
    int loop=0;
    int si;
    char opt,check;
    FILE* fptr;

    do{

    fptr = fopen("staff_data.txt","r");

    printf("\n");
    printf("+=====================================   +++++++++++++++++++++   ======================================+\n");
    printf("+=====================================   + SEARCH LEAVE INFO +   ======================================+\n");
    printf("+=====================================   +++++++++++++++++++++   ======================================+\n\n");

    do{

            printf("Enter the staff'ID: ");
            if(scanf("%d",&si) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(si));


    while(fread(&sd,sizeof(struct staff_data),1,fptr)){

        if(sd.staff_id==si){
        
        loop=1;
        
        printf("Staff name                        : %s %s\n",sd.fname,sd.lname);
        printf("Staff_ID                          : %d\n",sd.staff_id);
        printf("Staff Email Address               : %s\n",sd.email);
        printf("Staff's working department        : %s\n",sd.dpt);
        printf("The remaining annual leave        : %d\n",sd.al);
        printf("The remaining compassionate leave : %d\n",sd.cl);
        printf("The remaining emergency leave     : %d\n",sd.el);
        printf("The remaining maternity leave     : %d\n",sd.matl);
        printf("The remaining medical leave       : %d\n",sd.medl);
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++\n");

    }

    }

    if(!loop){

        printf("There's no record of the employee\n");
        printf("---------------------------------\n");

    }

    fclose(fptr);


    printf("\nDo you want to search another staff?(y - continue/any key - exit): ");
    scanf("%s",&opt);

}while(opt=='y'||opt=='Y');

}

void add_staff_info() {

    struct staff_data sd;
    char opt,check;
    int choice,loop;
    FILE* fptr;

    do{

        printf("\n");
        printf("+=====================================   ++++++++++++++++++   ======================================+\n");
        printf("+=====================================   + ADD STAFF INFO +   ======================================+\n");
        printf("+=====================================   ++++++++++++++++++   ======================================+\n\n");

        fptr = fopen("staff_data.txt","a");
        printf("\nNote: No spaces are needed\n");
        printf("----------------------------\n");
        printf("Enter the first name of the staff     : ");
        scanf("%s",sd.fname);
        printf("Enter the last name of the staff      : ");
        scanf("%s",sd.lname);

        do{

            printf("Enter the staff'ID                    : ");
            if(scanf("%d",&sd.staff_id) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(sd.staff_id));
        

        do{
        
        printf("--------------------------");
        printf("\n1. academic\n2. administration\n3. management\n4. technical\n");
        printf("--------------------------\n");
        printf("Enter the staff working department    : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1:strcpy(sd.dpt,"academic");loop='n';break;
            case 2:strcpy(sd.dpt,"administration");loop='n';break;
            case 3:strcpy(sd.dpt,"management");loop='n';break;
            case 4:strcpy(sd.dpt,"technical");loop='n';break;
            default: printf("\nInvalid Input!Please re-enter!\n");loop='y';break;
        }
        }while(loop=='y');

        
        printf("Enter the staff'email address         : ");
        scanf("%s",sd.email);
        printf("Enter the given annual leave          : ");
        scanf("%d",&sd.al);
        printf("Enter the given compassionate leave   : ");
        scanf("%d",&sd.cl);
        printf("Enter the given emergency leave       : ");
        scanf("%d",&sd.el);
        printf("Enter the given maternity leave       : ");
        scanf("%d",&sd.matl);
        printf("Enter the given medical leave         : ");
        scanf("%d",&sd.medl);
       
        printf("\n\n");

        if(fptr==NULL){
            printf("Can't open file\n");
        }else{
            printf("Staff Information is stored successfully\n");
            printf("----------------------------------------\n");
        }

        fwrite(&sd,sizeof(struct staff_data),1,fptr);
        fclose(fptr);

        printf("\nDo you want to record another new staff info?(y - continue/any key - exit): ");
        scanf("%s",&opt);

    }while(opt=='y'||opt=='Y');

    printf("\n");

}

void view_staff_data() {

    struct staff_data sd;
    FILE* fptr;
    fptr = fopen("staff_data.txt","r");
    printf("\n");
    printf("+=====================================   +++++++++++++++++++   ======================================+\n");
    printf("+=====================================   + VIEW STAFF INFO +   ======================================+\n");
    printf("+=====================================   +++++++++++++++++++   ======================================+\n\n");

    if(fptr==NULL){
        printf("Can't open file\n");
    }

    while(fread(&sd,sizeof(struct staff_data),1,fptr)){
    printf("Staff name                        : %s %s\n",sd.fname,sd.lname);
    printf("Staff_ID                          : %d\n",sd.staff_id);
    printf("Staff Email Address               : %s\n",sd.email);
    printf("Staff's working department        : %s\n",sd.dpt);
    printf("The remaining annual leave        : %d\n",sd.al);
    printf("The remaining compassionate leave : %d\n",sd.cl);
    printf("The remaining emergency leave     : %d\n",sd.el);
    printf("The remaining maternity leave     : %d\n",sd.matl);
    printf("The remaining medical leave       : %d\n",sd.medl);
    printf("__________________________________________________________\n\n");

    }
    fclose(fptr); 

}

void update_staff_data() {

    struct staff_data sd;
    int loop=0,choice,loop2;
    int i;
    char opt,check,check2;
    FILE* fptr,*fnew;

    do{

    fptr = fopen("staff_data.txt","r");
    fnew = fopen("staff_data_n.txt","w");

    printf("\n");
    printf("+=====================================   +++++++++++++++++++++   ======================================+\n");
    printf("+=====================================   + UPDATE STAFF INFO +   ======================================+\n");
    printf("+=====================================   +++++++++++++++++++++   ======================================+\n\n");

    do{

            printf("Enter the staff's ID that you would like to make update: ");
            if(scanf("%d",&i) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(i));

    printf("\n");

    while(fread(&sd,sizeof(struct staff_data),1,fptr)){

        if(sd.staff_id==i){
        
        loop=1;

        printf("+   + PREVIOUS RECORD OF THE STAFF +   +\n");
        printf("+   --------------------------------   +\n\n");

        printf("Staff name                        : %s %s\n",sd.fname,sd.lname);
        printf("Staff_ID                          : %d\n",sd.staff_id);
        printf("Staff Email Address               : %s\n",sd.email);
        printf("Staff's working department        : %s\n",sd.dpt);
        printf("The remaining annual leave        : %d\n",sd.al);
        printf("The remaining compassionate leave : %d\n",sd.cl);
        printf("The remaining emergency leave     : %d\n",sd.el);
        printf("The remaining maternity leave     : %d\n",sd.matl);
        printf("The remaining medical leave       : %d\n",sd.medl);
        printf("__________________________________________________________\n\n");

        printf("\nNote: No spaces are needed\n");
        printf("----------------------------\n");
        printf("Enter the new first name of the staff     : ");
        scanf("%s",sd.fname);
        printf("Enter the new last name of the staff      : ");
        scanf("%s",sd.lname);

        do{

            printf("Enter the new staff'ID                    : ");
            if(scanf("%d",&sd.staff_id) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check2 = getchar()) !='\n' && check2 != EOF){};  
            }

            else{break;}

        }while(!isdigit(sd.staff_id));


        do{
        
        printf("--------------------------");
        printf("\n1. academic\n2. administration\n3. management\n4. technical\n");
        printf("--------------------------\n");
        printf("Enter the new staff working department    : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1:strcpy(sd.dpt,"academic");loop2='n';break;
            case 2:strcpy(sd.dpt,"administration");loop2='n';break;
            case 3:strcpy(sd.dpt,"management");loop2='n';break;
            case 4:strcpy(sd.dpt,"technical");loop2='n';break;
            default: printf("\nInvalid Input!Please re-enter\n");loop2='y';break;
        }
        }while(loop2=='y');

        printf("Enter the new staff'email address         : ");
        scanf("%s",sd.email);
        printf("Enter the new given annual leave          : ");
        scanf("%d",&sd.al);
        printf("Enter the new given compassionate leave   : ");
        scanf("%d",&sd.cl);
        printf("Enter the new given emergency leave       : ");
        scanf("%d",&sd.el);
        printf("Enter the new given maternity leave       : ");
        scanf("%d",&sd.matl);
        printf("Enter the new given medical leave         : ");
        scanf("%d",&sd.medl);
       
        printf("\n\n");
        fwrite(&sd,sizeof(struct staff_data),1,fnew);
        
    }else{

        fwrite(&sd,sizeof(struct staff_data),1,fnew);
    }
    }

    fclose(fptr);
    fclose(fnew);

    if(loop){
        remove("staff_data.txt");
        rename("staff_data_n.txt","staff_data.txt");
        printf("The staff information has been updated successfully\n");
        printf("---------------------------------------------------\n");
    }


    if(!loop){

        printf("Record Not Found\n");

    }



    printf("\nDo you want to search another leave?(y - continue/any key - exit): ");
    scanf("%s",&opt);

}while(opt=='y'||opt=='Y');


}

void g_report() {

    FILE* fptr,*fptr2,*fptr3;

    fptr = fopen("leave_record_h.txt","r");
    fptr2 = fopen("leave_A.txt","r");
    fptr3 = fopen("leave_R.txt","r");

    struct staff la;
    struct staff_data sd;
    struct staff_lar lar;

    float conA = 0;
    float conR = 0;
    float conT = 0;
    float conTT = 0;
    int al=0,cl=0,el=0,matl=0,medl=0;

    printf("+========================================   ++++++++++++++++++   ==================================================+\n");
    printf("+========================================   + MONTHLY REPORT +   ==================================================+\n");
    printf("+========================================   ++++++++++++++++++   ==================================================+\n\n");

    printf("DEPARTMENT: ACADEMIC\n");
    printf("--------------------\n\n");

    while(fread(&la,sizeof(struct staff),1,fptr)){

        if(strcmp(la.dpt,"academic")==0){
            conT+=1;        

            if(strcmp(la.rfl,"Annual Leave")==0){
            al+=1;}

            if(strcmp(la.rfl,"Compassionate Leave")==0){
            cl+=1;}

            if(strcmp(la.rfl,"Emergency Leave")==0){
            el+=1;}

            if(strcmp(la.rfl,"Maternity Leave")==0){
            matl+=1;}

            if(strcmp(la.rfl,"Medical Leave")==0){
            medl+=1;}
        
        }

        

    }
    conTT = (conT/150)*100;
    

    while(fread(&lar,sizeof(struct staff_lar),1,fptr2)){

        if(strcmp(lar.dpt,"academic")==0){
            conA+=1;
        }
    }

    while(fread(&lar,sizeof(struct staff_lar),1,fptr3)){

        if(strcmp(lar.dpt,"academic")==0){
            conR+=1;
        }
    }


    printf("The total number of leave application is : %.f\n\n",conT);

    printf("The total number of leave approved is    : %.f\n\n",conA);

    printf("The total number of leave rejected is    : %.f\n\n",conR);
    
    printf("The percentage of leave application is   : %.2lf\n\n",conTT);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    printf("The number of employees who ask for Annual Leave        : %d\n",al);
    printf("The number of employees who ask for Compassionate Leave : %d\n",cl);
    printf("The number of employees who ask for Emergency Leave     : %d\n",el);
    printf("The number of employees who ask for Maternity Leave     : %d\n",matl);
    printf("The number of employees who ask for Medical Leave       : %d\n\n",medl);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);

    
    fptr = fopen("leave_record_h.txt","r");
    fptr2 = fopen("leave_A.txt","r");
    fptr3 = fopen("leave_R.txt","r");

    printf("DEPARTMENT: ADMINISTRATION\n");
    printf("--------------------------\n\n");

    float conA1 = 0;
    float conR2 = 0;
    float conT3 = 0;
    float conTT3 = 0;
    int al2=0,cl2=0,el2=0,matl2=0,medl2=0;

    while(fread(&la,sizeof(struct staff),1,fptr)){

        if(strcmp(la.dpt,"administration")==0){
            conT3+=1;         

            if(strcmp(la.rfl,"Annual Leave")==0){
            al2+=1;}

            if(strcmp(la.rfl,"Compassionate Leave")==0){
            cl2+=1;}

            if(strcmp(la.rfl,"Emergency Leave")==0){
            el2+=1;}

            if(strcmp(la.rfl,"Maternity Leave")==0){
            matl2+=1;}

            if(strcmp(la.rfl,"Medical Leave")==0){
            medl2+=1;}
        
        }

        

    }
    conTT3 = (conT3/150)*100;

    while(fread(&lar,sizeof(struct staff_lar),1,fptr2)){

        if(strcmp(lar.dpt,"administration")==0){
            conA1+=1;
        }
    }

    while(fread(&lar,sizeof(struct staff_lar),1,fptr3)){

        if(strcmp(lar.dpt,"administration")==0){
            conR2+=1;
        }
    }

    printf("The total number of leave application is : %.f\n\n",conT3);

    printf("The total number of leave approved is    : %.f\n\n",conA1);

    printf("The total number of leave rejected is    : %.f\n\n",conR2);

    printf("The percentage of leave application is   : %.2lf\n\n",conTT3);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    printf("The number of employees who ask for Annual Leave        : %d\n",al2);
    printf("The number of employees who ask for Compassionate Leave : %d\n",cl2);
    printf("The number of employees who ask for Emergency Leave     : %d\n",el2);
    printf("The number of employees who ask for Maternity Leave     : %d\n",matl2);
    printf("The number of employees who ask for Medical Leave       : %d\n\n",medl2);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);

    fptr = fopen("leave_record_h.txt","r");
    fptr2 = fopen("leave_A.txt","r");
    fptr3 = fopen("leave_R.txt","r");


    printf("DEPARTMENT: MANAGEMENT\n");
    printf("----------------------\n\n");

    float conA4 = 0;
    float conR5 = 0;
    float conT6 = 0;
    float conTT6 = 0;
    int al3=0,cl3=0,el3=0,matl3=0,medl3=0;

     while(fread(&la,sizeof(struct staff),1,fptr)){

        if(strcmp(la.dpt,"management")==0){
            conT6+=1;

            if(strcmp(la.rfl,"Annual Leave")==0){
            al3+=1;}

            if(strcmp(la.rfl,"Compassionate Leave")==0){
            cl3+=1;}

            if(strcmp(la.rfl,"Emergency Leave")==0){
            el3+=1;}

            if(strcmp(la.rfl,"Maternity Leave")==0){
            matl3+=1;}

            if(strcmp(la.rfl,"Medical Leave")==0){
            medl3+=1;}
        
        } 

        

    }
    conTT6 = (conT6/150)*100;

    while(fread(&lar,sizeof(struct staff_lar),1,fptr2)){

        if(strcmp(lar.dpt,"management")==0){
            conA4+=1;
        }
    }

    while(fread(&lar,sizeof(struct staff_lar),1,fptr3)){

        if(strcmp(lar.dpt,"management")==0){
            conR5+=1;
        }
    }

    printf("The total number of leave application is: %.f\n\n",conT6);

    printf("The total number of leave approved is: %.f\n\n",conA4);

    printf("The total number of leave rejected is: %.f\n\n",conR5);

    printf("The percentage of leave application is: %.2lf\n\n",conTT6);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    printf("The number of employees who ask for Annual Leave        : %d\n",al3);
    printf("The number of employees who ask for Compassionate Leave : %d\n",cl3);
    printf("The number of employees who ask for Emergency Leave     : %d\n",el3);
    printf("The number of employees who ask for Maternity Leave     : %d\n",matl3);
    printf("The number of employees who ask for Medical Leave       : %d\n\n",medl3);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);

    fptr = fopen("leave_record_h.txt","r");
    fptr2 = fopen("leave_A.txt","r");
    fptr3 = fopen("leave_R.txt","r");


    printf("DEPARTMENT: TECHNICAL\n");
    printf("---------------------\n\n");

    float conA7 = 0;
    float conR8 = 0;
    float conT9 = 0;
    float conTT9 = 0;
    int al4=0,cl4=0,el4=0,matl4=0,medl4=0;

    while(fread(&la,sizeof(struct staff),1,fptr)){

        if(strcmp(la.dpt,"technical")==0){
            conT9+=1;      

            if(strcmp(la.rfl,"Annual Leave")==0){
            al4+=1;}

            if(strcmp(la.rfl,"Compassionate Leave")==0){
            cl4+=1;}

            if(strcmp(la.rfl,"Emergency Leave")==0){
            el4+=1;}

            if(strcmp(la.rfl,"Maternity Leave")==0){
            matl4+=1;}

            if(strcmp(la.rfl,"Medical Leave")==0){
            medl4+=1;}
        
        }  

         

    }
    conTT9 = (conT9/150)*100;


    while(fread(&lar,sizeof(struct staff_lar),1,fptr2)){

        if(strcmp(lar.dpt,"technical")==0){
            conA7+=1;
        }
    }

    while(fread(&lar,sizeof(struct staff_lar),1,fptr3)){

        if(strcmp(lar.dpt,"technical")==0){
            conR8+=1;
        }
    }

    printf("The total number of leave application is: %.f\n\n",conT9);

    printf("The total number of leave approved is: %.f\n\n",conA7);

    printf("The total number of leave rejected is: %.f\n\n",conR8);

    printf("The percentage of leave application is: %.2lf\n\n",conTT9);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    printf("The number of employees who ask for Annual Leave        : %d\n",al4);
    printf("The number of employees who ask for Compassionate Leave : %d\n",cl4);
    printf("The number of employees who ask for Emergency Leave     : %d\n",el4);
    printf("The number of employees who ask for Maternity Leave     : %d\n",matl4);
    printf("The number of employees who ask for Medical Leave       : %d\n\n",medl4);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");


    
    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);



}



void adm() {

    int choice;
    while(choice!=6){
    printf("+========================================   ++++++++++++++   ==================================================+\n");
    printf("+========================================   + ADMIN PAGE +   ==================================================+\n");
    printf("+========================================   ++++++++++++++   ==================================================+\n\n");

    printf("1.Add New Staff's Information\n");
    printf("2.Update The Leave Balance\n");
    printf("3,View Staff Information\n");
    printf("4.Search For Staff's Leave Information\n");
    printf("5.Generate Monthly Report\n");
    printf("6.Exit\n\n");

    printf("Please enter your choice: ");
    scanf("%d",&choice);
    getchar();

    switch (choice){
        case 1:

            add_staff_info();

            break;

        case 2:

            update_staff_data();

            break;

        case 3:

            view_staff_data();

            break;

        case 4:

            search_leave();

            break;

        case 5:

            g_report();

            break;

        case 6:
            printf("\n");
            break;
        default:printf("Invalid entry\n\n");
    }

    }

}

void leave_ar() {

    struct staff la; //view leave application
    struct staff_lar lar; //record the leave approval and rejection
    char opt,check;
    int sas,choice,cont,cont2,choice2,loop2;
    int loop=0,found=0;
    FILE* fptr,*fptr2,*fnew,*fnew2,*fnew3;

    do{

    fptr = fopen("leave_record.txt","r");
    fnew = fopen("leave_A.txt","a");
    fnew2 =fopen("leave_R.txt","a");
    fnew3 = fopen("record_temp.txt","w");

    printf("\n");
    printf("+=====================================   ++++++++++++++++++++++++++   ======================================+\n");
    printf("+=====================================   + VIEW LEAVE APPLICATION +   ======================================+\n");
    printf("+=====================================   ++++++++++++++++++++++++++   ======================================+\n\n");

    while(fread(&la,sizeof(struct staff),1,fptr)){
    found = 1;
    printf("Staff name           : %s %s\n",la.fname,la.lname);
    printf("Staff_ID             : %d\n",la.staff_id);
    printf("Working department   : %s\n",la.dpt);
    printf("Leave Reason         : %s\n",la.rfl);
    printf("Starting day         : %d\n",la.sd);
    printf("Starting month       : %d\n",la.sm);
    printf("Starting year        :2023\n");
    printf("Ending day           : %d\n",la.ed);
    printf("Ending month         : %d\n",la.em);
    printf("Ending year          :2023\n");
    printf("_______________________________________\n\n");
    printf("The duration day of leave taken: %d\n\n",la.dl_d);
    printf("The duration month of leave taken: %d\n\n",la.dl_m);
    printf("=======================================\n\n");}

    if(found == 0){
        printf("No leave application found\n");
        printf("--------------------------\n\n");
        break;
    }


    fclose(fptr);


    fptr = fopen("leave_record.txt","r");

    printf("Leave Approval & Rejection Section\n");
    printf("----------------------------------\n\n");

    do{

            printf("Enter the staff's ID that you would like response on: ");
            if(scanf("%d",&sas) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(sas));

    printf("\n");


    while(fread(&la,sizeof(struct staff),1,fptr)){
    if(la.staff_id==sas){

        loop=1;

        do{

            printf("Please re-enter the staff ID: ");
            if(scanf("%d",&lar.sid) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(lar.sid));

        printf("\n");

        do{
        
        printf("-----------------------------------------");
        printf("\n1. academic\n2. administration\n3. management\n4. technical\n\n");
        printf("Please enter the staff's department : ");
        scanf("%d",&choice2);
        getchar();
        printf("-----------------------------------------\n");

        switch(choice2){
            case 1:strcpy(lar.dpt,"academic");loop2='n';break;
            case 2:strcpy(lar.dpt,"administration");loop2='n';break;
            case 3:strcpy(lar.dpt,"management");loop2='n';break;
            case 4:strcpy(lar.dpt,"technical");loop2='n';break;
            default: printf("\nInvalid Input!Please re-enter\n");loop2='y';break;
        }
        }while(loop2=='y');

        printf("\n");

        do{
        
        printf("-----------------------------------------\n");
        printf("1.Approve\n2.Reject\n\n");
        printf("Enter the leave application status : ");
        scanf("%d",&choice);
        getchar();
        printf("-----------------------------------------\n");

        switch(choice){
            case 1:strcpy(lar.ar,"Approved");cont='n'; 
                   printf("\nPlease enter the given leave days: ");
                   scanf("%d",&lar.dl_d);
                   printf("\nPlease enter the given leave month: ");
                   scanf("%d",&lar.dl_m);
                   printf("\n");

                do{

                    printf("-----------------------------------------\n");
                    printf("\n1. Annual Leave\n2. Compassionate Leave\n3. Emergency Leave\n4. Maternity Leave\n5. Medical Leave\n\n");
                    printf("Reason for leave      : ");
                    scanf("%d",&choice);
                    getchar();
                    printf("-----------------------------------------\n");

                    switch(choice){
                        case 1:strcpy(lar.rfl,"Annual Leave");loop='n';break;
                        case 2:strcpy(lar.rfl,"Compassionate Leave");loop='n';break;
                        case 3:strcpy(lar.rfl,"Emergency Leave");loop='n';break;
                        case 4:strcpy(lar.rfl,"Maternity Leave");loop='n';break;
                        case 5:strcpy(lar.rfl,"Medical Leave");loop='n';break;
                        default: printf("\nInvalid Input!Please re-enter\n");loop='y';break;}
    
                }while(cont2=='y');

                   fwrite(&lar,sizeof(struct staff_lar),1,fnew);break;

            case 2:strcpy(lar.ar,"Rejected");cont='n';fwrite(&lar,sizeof(struct staff_lar),1,fnew2);break;
            default: printf("\nInvalid Input!Please re-enter\n");cont='y';break;
        }

        }while(cont=='y');

    }

    if(la.staff_id != sas){
        fwrite(&la,sizeof(struct staff),1,fnew3);
    }

    
    }

    if(!loop){

        printf("Staff ID don't exist\n");
        printf("--------------------\n");

    }


    fclose(fptr);
    fclose(fnew);
    fclose(fnew2);
    fclose(fnew3);

    remove("leave_record.txt");
    rename("record_temp.txt","leave_record.txt");


    printf("\nDo you want to search another leave?(y - continue/any key - exit): ");
    scanf("%s",&opt);

}while(opt=='y'||opt=='Y');

    
}

void search_date() {

    struct staff la;
    int loop=0;
    int si,si2,si3;
    char opt,check;
    FILE* fptr;

    do{

    fptr = fopen("leave_record_h.txt","r");

    printf("\n");
    printf("+=====================================   +++++++++++++++++++++   ======================================+\n");
    printf("+=====================================   + SEARCH LEAVE INFO +   ======================================+\n");
    printf("+=====================================   +++++++++++++++++++++   ======================================+\n\n");

    do{

            printf("Enter the leave day: ");
            if(scanf("%d",&si) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(si));

    printf("\n");

    do{

            printf("Enter the leave month: ");
            if(scanf("%d",&si2) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(si2));

    printf("\n");

    printf("Enter the leave year  : 2023");

    printf("\n");

    while(fread(&la,sizeof(struct staff),1,fptr)){

        if(la.sd==si && la.sm==si2 ){
        
        loop=1;
        
        printf("Staff's Name        : %s %s\n",la.fname,la.lname);
        printf("Staff's ID          : %d\n",la.staff_id);
        printf("Reason For Leave    : %s\n",la.rfl);
        printf("Leave's apply day   : %d\n",la.sd);
        printf("Leave's apply month : %d\n",la.sm);
        printf("Leave's apply year  :2023\n");
        printf("Leave's end day     : %d\n",la.ed);
        printf("Leave's end month   : %d\n",la.em);
        printf("Leave's end year    :2023\n");
        printf("\n+++++++++++++++++++++++++++++++\n");

        }
    }

       

    if(!loop){

        printf("There's no leave application on this day\n");

    }

    fclose(fptr);


    printf("\nDo you want to search another leave?(y - continue/any key - exit): ");
    scanf("%s",&opt);

    }while(opt=='y'||opt=='Y');
     
}





void spv() {

    int choice;

    while(choice!=3){
    printf("+========================================   +++++++++++++++++++   =============================================+\n");
    printf("+========================================   + SUPERVISOR PAGE +   =============================================+\n");
    printf("+========================================   +++++++++++++++++++   =============================================+\n\n");

    printf("1.Leave Approval & Rejection\n");
    printf("2.View Date Of Leave Application\n");
    printf("3.Exit\n");

    printf("Please enter your choice: ");
    scanf("%d",&choice);
    getchar();
    switch (choice){

        case 1:

            leave_ar();

            break;

        case 2:

            search_date();

            break;

        case 3:
            printf("\n");
            break;
        
        default:printf("Invalid entry\n\n");
    }
    }

}

void leave_apply() {

    char opt;
    int check,check2,check3,check4,check5,check6,check7,record_found=0;
    int choice,loop,choice2,loop2;
    FILE* fptr,*fptr2,*fptr3;
    struct staff la;

    fptr2 = fopen("leave_record.txt","r");

        printf("Note: Leave application are not allow while the previous request is still on pending\n");
        printf("------------------------------------------------------------------------------------\n");

        do{

            printf("Enter your staff'ID: ");
            if(scanf("%d",&check) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check2 = getchar()) !='\n' && check2 != EOF){};  
            }

            else{break;}

        }while(!isdigit(check));

    while(fread(&la,sizeof(struct staff),1,fptr2)){

            if(la.staff_id==check){
                record_found =1;
                printf("Record found, no leave application are permitted\n");
                break;
            }
    }
            
            fclose(fptr2);

    if(!record_found){

        do{
      
        printf("\n");
        printf("+=====================================   +++++++++++++++   ======================================+\n");
        printf("+=====================================   + APPLY LEAVE +   ======================================+\n");
        printf("+=====================================   +++++++++++++++   ======================================+\n\n");

        fptr = fopen("leave_record.txt","a");
        fptr3 = fopen("leave_record_h.txt","a");
        printf("\nNote: No spaces are needed\n");
        printf("----------------------------\n");
        printf("Enter your first name        : ");
        scanf("%s",la.fname);
        printf("Enter your last name         : ");
        scanf("%s",la.lname);

        do{

            printf("Please re-enter your staff'ID: ");
            if(scanf("%d",&la.staff_id) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check3 = getchar()) !='\n' && check3 != EOF){};  
            }

            else{break;}

        }while(!isdigit(la.staff_id));


        do{
        
        printf("----------------------------------");
        printf("\n1. academic\n2. administration\n3. management\n4. technical\n");
        printf("----------------------------------\n");
        printf("Enter your working department: ");
        scanf("%d",&choice2);
        getchar();

        switch(choice2){
            case 1:strcpy(la.dpt,"academic");loop2='n';break;
            case 2:strcpy(la.dpt,"administration");loop2='n';break;
            case 3:strcpy(la.dpt,"management");loop2='n';break;
            case 4:strcpy(la.dpt,"technical");loop2='n';break;
            default: printf("\nInvalid Input!Please re-enter\n");loop2='y';break;
        }
        }while(loop2=='y');

        do{
        
        printf("----------------------------------");
        printf("\n1. Annual Leave\n2. Compassionate Leave\n3. Emergency Leave\n4. Maternity Leave\n5. Medical Leave\n");
        printf("----------------------------------\n");
        printf("Reason for leave      : ");
        scanf("%d",&choice);
        getchar();
        printf("----------------------------------\n");

        switch(choice){
            case 1:strcpy(la.rfl,"Annual Leave");loop='n';break;
            case 2:strcpy(la.rfl,"Compassionate Leave");loop='n';break;
            case 3:strcpy(la.rfl,"Emergency Leave");loop='n';break;
            case 4:strcpy(la.rfl,"Maternity Leave");loop='n';break;
            case 5:strcpy(la.rfl,"Medical Leave");loop='n';break;
            default: printf("\nInvalid Input!Please re-enter\n");loop='y';break;
        }
        }while(loop=='y');


        do{

            printf("Starting_day          : ");
            if(scanf("%d",&la.sd) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check4 = getchar()) !='\n' && check4 != EOF){};  
            }

            else{break;}

        }while(!isdigit(la.sd));

        printf("\n");

        do{

            printf("Starting_month        : ");
            if(scanf("%d",&la.sm) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check5 = getchar()) !='\n' && check5 != EOF){};  
            }

            else{break;}

        }while(!isdigit(la.sm));

        printf("\n");
        printf("Starting_year         :2023\n");
        printf("\n");

        do{

            printf("End_day               : ");
            if(scanf("%d",&la.ed) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check6 = getchar()) !='\n' && check6 != EOF){};  
            }

            else{break;}

        }while(!isdigit(la.ed));

        printf("\n");

        do{

            printf("End_month             : ");
            if(scanf("%d",&la.em) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check7 = getchar()) !='\n' && check7 != EOF){};  
            }

            else{break;}

        }while(!isdigit(la.em));

        printf("\n");
        printf("End_year              :2023\n");
        printf("\n\n");

        la.dl_d = la.ed-la.sd;
        la.dl_m = la.em-la.sm;

        if(fptr==NULL){
            printf("Can't open file\n");
        }else{
            printf("Leave Application is stored successfully\n");
        }

        fwrite(&la,sizeof(struct staff),1,fptr);
        fwrite(&la,sizeof(struct staff),1,fptr3);

        fclose(fptr);
        fclose(fptr3);

        printf("\nDo you want to apply another leave?(y - continue/any key - exit): ");
        scanf("%s",&opt);

    }while(opt=='y'||opt=='Y');
          
        
    printf("\n");
  
    }
    
}

void cancel_leave() {

    struct staff la;
    int loop=0;
    int si;
    char opt,check;
    FILE* fptr,*fnew;

    do{

    fptr = fopen("leave_record.txt","r");
    fnew = fopen("leave_record_n.txt","w");

    printf("\n");
    printf("+=====================================   ++++++++++++++++   ======================================+\n");
    printf("+=====================================   + Cancel Leave +   ======================================+\n");
    printf("+=====================================   ++++++++++++++++   ======================================+\n\n");

    do{

            printf("Enter the staff'ID: ");
            if(scanf("%d",&si) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(si));

    printf("\n");

    if(fptr==NULL){

        printf("Can't open file");
    }

    while(fread(&la,sizeof(struct staff),1,fptr)){

        if(la.staff_id==si){       
        loop=1;
    } else{

        fwrite(&la,sizeof(struct staff),1,fnew);
    }
    }


    fclose(fptr);
    fclose(fnew);

    if(loop){
        remove("leave_record.txt");
        rename("leave_record_n.txt","leave_record.txt");
        printf("Your leave application has been successfully cancelled\n");
        printf("------------------------------------------------------\n");
    }


    if(!loop){

        printf("\n");
        printf("Record Not Found\n");
        printf("----------------\n");

    }


    printf("\nDo you want to cancel another leave?(y - continue/any key - exit): ");
    scanf("%s",&opt);

}while(opt=='y'||opt=='Y');


}

void check_leave_status() {

    FILE* fptr,*fnew,*fnew2;
    char opt,check;
    struct staff la;
    struct staff_lar lar;
    int sas;
    int loop=0;

    do{

        printf("+=====================================   ++++++++++++++++++++++   ======================================+\n");
        printf("+=====================================   + CHECK LEAVE STATUS +   ======================================+\n");
        printf("+=====================================   ++++++++++++++++++++++   ======================================+\n\n");

        fptr = fopen("leave_record_h.txt","r");
        fnew = fopen("leave_A.txt","r");
        fnew2 = fopen("leave_R.txt","r");
        
        do{

            printf("Please enter your staff ID: ");
            if(scanf("%d",&sas) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(sas));


        while(fread(&la,sizeof(struct staff),1,fptr)){

        if(la.staff_id==sas){
        
        loop=1;

        printf("\n");
        printf("Staff's Name        : %s %s\n",la.fname,la.lname);
        printf("Staff's ID          : %d\n",la.staff_id);
        printf("Working department  : %s\n",la.dpt);
        printf("Reason For Leave    : %s\n",la.rfl);
        printf("Leave's apply day   : %d\n",la.sd);
        printf("Leave's apply month : %d\n",la.sm);
        printf("Leave's apply year  :2023\n");
        printf("Leave's end day     : %d\n",la.ed);
        printf("Leave's end month   : %d\n",la.em);
        printf("Leave's end year    :2023\n");
        printf("\n+++++++++++++++++++++++++++++++\n");

    }

    if(!loop){
        
        printf("\n");
        printf("Record not found\n");
        printf("----------------\n");

    }

    }

    while(fread(&lar,sizeof(struct staff_lar),1,fnew)){

        if(lar.sid==sas){

            loop=1;

            printf("Your Leave Application Status: %s",lar.ar);
            printf("\n");

        }


    }

    while(fread(&lar,sizeof(struct staff_lar),1,fnew2)){

        if(lar.sid==sas){

            loop=1;

            printf("Your Leave Application Status: %s",lar.ar);
            printf("\n");

        }


    }


    printf("\nDo you want to check another record?(y - continue/any key - exit): ");
    scanf("%s",&opt);

    }while(opt=='y'||opt=='Y');

}


void check_summary() {

    FILE* fptr,*fptr2;
    struct staff_lar lar;
    struct staff_data sd;
    int sas;
    int loop = 0;
    char opt,check;
    int tem;

    do{

        printf("+=====================================   +++++++++++++++++   ======================================+\n");
        printf("+=====================================   + CHECK SUMMARY +   ======================================+\n");
        printf("+=====================================   +++++++++++++++++   ======================================+\n\n");

        fptr = fopen("leave_A.txt","r");
        fptr2 = fopen("staff_data.txt","r");


        do{

            printf("Please enter your staff'ID: ");
            if(scanf("%d",&sas) !=1){
              printf("\nInvalid input. Please enter a digit.\n\n");
              while ((check = getchar()) !='\n' && check != EOF){};  
            }

            else{break;}

        }while(!isdigit(sas));

        printf("\n\n");

        //loop = 0;

        while(fread(&sd,sizeof(struct staff_data),1,fptr2)){

            if(sd.staff_id==sas){

                loop=1;

                printf("YOUR LEAVE INFOMATION\n");
                printf("---------------------\n\n");

                printf("The previous annual leave        : %d\n",sd.al);
                printf("The previous compassionate leave : %d\n",sd.cl);
                printf("The previous emergency leave     : %d\n",sd.el);
                printf("The previous maternity leave     : %d\n",sd.matl);
                printf("The previous medical leave       : %d\n\n",sd.medl);
            }


        }

        fclose(fptr2);

        loop=0;

        fptr2 = fopen("staff_data.txt","r");

        while(fread(&sd,sizeof(struct staff_data),1,fptr2)){

            if(sd.staff_id==sas){

                loop=1;

                while(fread(&lar,sizeof(struct staff_lar),1,fptr)){

                if(lar.sid==sas){

                printf("YOUR UPDATED LEAVE INFOMATION\n");
                printf("-----------------------------\n\n");

                if(strcmp(lar.rfl,"Annual Leave")==0){

                    tem=sd.al-lar.dl_d;

                    printf("Leave remaining for annual leave        : %d\n",tem);
                    printf("Leave remaining for compassionate leave : %d\n",sd.cl);             
                    printf("Leave remaining for emergency leave     : %d\n",sd.el);
                    printf("Leave remaining for maternity leave     : %d\n",sd.matl);
                    printf("Leave remaining for medical leave       : %d\n",sd.medl);

                }

                if(strcmp(lar.rfl,"Compassionate Leave")==0){

                    tem=sd.cl-lar.dl_d;

                    printf("Leave remaining for annual leave        : %d\n",sd.al);
                    printf("Leave remaining for compassionate leave : %d\n",tem);
                    printf("Leave remaining for emergency leave     : %d\n",sd.el);
                    printf("Leave remaining for maternity leave     : %d\n",sd.matl);
                    printf("Leave remaining for medical leave       : %d\n",sd.medl);             

                }

                if(strcmp(lar.rfl,"Emergency Leave")==0){

                    tem=sd.el-lar.dl_d;

                    printf("Leave remaining for annual leave        : %d\n",sd.al);
                    printf("Leave remaining for compassionate leave : %d\n",sd.cl);
                    printf("Leave remaining for emergency leave     : %d\n",tem);
                    printf("Leave remaining for maternity leave     : %d\n",sd.matl);
                    printf("Leave remaining for medical leave       : %d\n",sd.medl);             

                }

                if(strcmp(lar.rfl,"Maternity Leave")==0){

                    tem=sd.matl-lar.dl_d;

                    printf("Leave remaining for annual leave        : %d\n",sd.al);
                    printf("Leave remaining for compassionate leave : %d\n",sd.cl);
                    printf("Leave remaining for emergency leave     : %d\n",sd.el);
                    printf("Leave remaining for maternity leave     : %d\n",tem);    
                    printf("Leave remaining for medical leave       : %d\n",sd.medl);         

                }

                if(strcmp(lar.rfl,"Medical Leave")==0){

                    tem=sd.medl-lar.dl_d;

                    printf("Leave remaining for annual leave        : %d\n",sd.al);
                    printf("Leave remaining for compassionate leave : %d\n",sd.cl);
                    printf("Leave remaining for emergency leave     : %d\n",sd.el);
                    printf("Leave remaining for maternity leave     : %d\n",sd.matl);
                    printf("Leave remaining for medical leave       : %d\n",tem);             

                }

                }
              
            }

            }
            

        }

        if(!loop){
                
                printf("\n");
                printf("Record Not Found\n");
                printf("------------------\n");
            }

        fclose(fptr);
        fclose(fptr2);


        printf("\nDo you want to check another record?(y - continue/any key - exit): ");
        scanf("%s",&opt); 

        }while(opt=='y'|| opt=='Y');


    }


void staff() {

    int choice;
    while(choice!=5){

    printf("+========================================   ++++++++++++++   ==================================================+\n");
    printf("+========================================   + STAFF PAGE +   ==================================================+\n");
    printf("+========================================   ++++++++++++++   ==================================================+\n\n");

    printf("1.Apply Leave\n");
    printf("2.Cancel Leave\n");
    printf("3.Check Leave Status\n");
    printf("4.Check Summary Of Leave Informarion\n");
    printf("5.Exit\n\n");
    printf("Please enter your choice: ");
    scanf("%d",&choice);
    getchar();
    printf("\n\n");

    switch (choice){
        case 1:

            leave_apply();

            break;

        case 2:

            cancel_leave();

            break;

        case 3:

            check_leave_status();

            break;

        case 4:

            check_summary();

            break;

        case 5:
            printf("\n");
            break;
        
        default:printf("Invalid entry\n");
                printf("+++++++++++++\n\n");
    }

    }
    
}

int main (){


    int choice;
    char opt;
    do{

        printf("\n\n");

        printf("+==============================================================================================================+\n");
        printf("+=======================   ++++++++++++++++++++++++++++++++++++++++++++++++++++   =============================+\n");
        printf("+=======================   + Welcome TO Leave Application & Management System +   =============================+\n");
        printf("+=======================   ++++++++++++++++++++++++++++++++++++++++++++++++++++   =============================+\n");
        printf("+==============================================================================================================+\n\n");

        printf("1. Login\n");
        printf("2. Exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1: printf("\nTo proceed, kindlly fill the details below: \n");
                    printf("--------------------------------------------\n\n");

                    struct login{
                    char username[50];
                    char password[50];
                    } lgn; 

                    int check = 0;
                    char username[50];
                    char password[50];

                    FILE* fptr = fopen("staff_lgn.txt","rb");
                    FILE* fnew = fopen("admin_lgn.txt","r");
                    FILE* fnew2 = fopen("spv_lgn.txt","r");

                    printf("Enter username: ");
                    if (fgets(username, sizeof(username), stdin) != NULL) {
                        // Remove the trailing newline character, if present
                        username[strcspn(username, "\n")] = '\0';
                    } else {
                        fprintf(stderr, "Error reading username\n");
                        return 1;
                    }

                    printf("Enter password: ");
                    if (fgets(password, sizeof(password), stdin) != NULL) {
                        // Remove the trailing newline character, if present
                        password[strcspn(password, "\n")] = '\0';
                    } else {
                        fprintf(stderr, "Error reading password\n");
                        return 1;
                    }

                    while(fscanf(fptr,"%s   %s", lgn.username, lgn.password)!=EOF){
                        if(strcmp(username,lgn.username)==0){
                            if(strcmp(password,lgn.password)==0){
                                check = 1;
                                printf("\nLogin Successfully\n");
                                printf("++++++++++++++++++++++\n\n");
                                staff();                               
                                break;
                            }
                        }
                    }

                    while(fscanf(fnew,"%s   %s", lgn.username, lgn.password)!=EOF){
                        if(strcmp(username,lgn.username)==0){
                            if(strcmp(password,lgn.password)==0){
                                check = 1;
                                printf("\nLogin Successfully\n");
                                printf("++++++++++++++++++++++\n\n");                               
                                adm();
                                break;
                            }
                        }

                    }

                    while(fscanf(fnew2,"%s   %s", lgn.username, lgn.password)!=EOF){
                        if(strcmp(username,lgn.username)==0){
                            if(strcmp(password,lgn.password)==0){
                                check = 1;
                                printf("\nLogin Successfully\n");
                                printf("++++++++++++++++++++++\n\n");
                                spv();
                                break;
                            }
                        }

                    }


                    if(!check){
                        opt = 'y';
                        printf("\nYour username or password are invalid\n");
                        printf("---------------------------------------\n");
                    }

              
                    fclose(fptr);break;
                    fclose(fnew);
                    fclose(fnew2);

                    case 2: 
                        opt = 'n';
                        break;

                    default:printf("Invalid Input\n");
                            printf("+++++++++++++");
                            opt = 'y';break;


                    }


    }while(opt=='y');

    printf("\n");
    printf("+=====================================   ++++++++++++++++++++++++++   ======================================+\n");
    printf("+=====================================   + Hope To See You Again! +   ======================================+\n");
    printf("+=====================================   ++++++++++++++++++++++++++   ======================================+\n\n");

           

    return 0;

}