	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <time.h>
	#include<conio.h>
	#include<math.h>
	#define MAX_NAME_LENGTH 50
	// Khai báo biến kieu char
	const float esp=0.01;
	int ID[100];
	char Sfullname[MAX_NAME_LENGTH];
	char Sname[MAX_NAME_LENGTH];
	char Ename[MAX_NAME_LENGTH];
	char Elop[MAX_NAME_LENGTH];
	char Ekhoa[MAX_NAME_LENGTH];
	char Ediachi[MAX_NAME_LENGTH];
	char Eemail[MAX_NAME_LENGTH];
	char Egioitinh[MAX_NAME_LENGTH];
	char filename[MAX_NAME_LENGTH];
	char searchName[MAX_NAME_LENGTH];
	char Skhoa[MAX_NAME_LENGTH];
	char Slop[MAX_NAME_LENGTH];
	char Sdiachi[MAX_NAME_LENGTH];
	char Sgioitinh[MAX_NAME_LENGTH];
	char Semail[MAX_NAME_LENGTH];
	char tenfile[20];
	
	// Khai báo biến kieu int
	int tieude;
	int Sage;
	int Eday;
	int Emonth;
	int Eyear;
	int numberstudent;
	int choice;
	int select;
	int checkinput;
	//float
	float Stoan,Sly,Stin,Strungbinh;
	// Khai báo biến kieu int
	int SID;
	int EID;
	int DID;
	int EDS ;
	//------------------------
	void title(){
		for (int i=0 ; i<132; i++){
		printf("-");
	}
	printf("\n");
	    printf("\x1b[38;2;255;255;255m| \x1b[38;2;255;255;0m%73s \x1b[38;2;255;255;255m                                                       |\n", "DE TAI 920 : QUAN LY SINH VIEN");
	     printf("\x1b[38;2;255;255;255m| \x1b[38;2;255;255;0m%79s \x1b[38;2;255;255;255m                                                 |\n", "GIANG VIEN HUONG DAN : ThS.Do Thi Tuyet Hoa ");
	     printf("\x1b[38;2;255;255;255m| \x1b[38;2;255;255;0m%79s \x1b[38;2;255;255;255m                                                 |\n", "Ten sinh vien : Tran Van Huan  -  23T_Nhat2 ");
	    printf("\x1b[38;2;255;255;255m| \x1b[38;2;255;255;0m%79s \x1b[38;2;255;255;255m                                                 |\n", "Ten sinh vien : Pham Phu Khanh  -  23T_Nhat2");
	    printf("\x1b[38;2;255;255;255m| \x1b[38;2;255;255;0m%79s \x1b[38;2;255;255;255m                                                 |\n", "Nhom 04 (23.11A) ");
	for (int i=0 ; i<132; i++){
		printf("-");
	}
	}
	struct databirth{
		int day , month , year;
	};
	struct datascore{
		float toan , ly , tin ;
		float trungbinh;
		int hocbong ;
	};
	struct element{
		char name[50];
		int ID;
		int age;
	    char gioitinh[50];
	    char email[50];
	    char diachi[50];
	    char lop[50];
	    char khoa[50];
	};
	struct Node {
	       struct element student;
		  struct databirth birth;
	      struct datascore diem; 
	       struct Node*next;
	       struct Node*prev;
	};
	typedef struct Node *Student;
	typedef struct Node *position;
	float diemtb(Student s){
		float tmp=(s->diem.toan+s->diem.ly+s->diem.tin)/3;
		return tmp;
	}
	int hocbong(Student s){
		if (diemtb(s)>=8.0) return 200;
		if (diemtb(s)>=7.0) return 100;
		return 0;
	}
	// ham tinh tuoi
	int tinh_tuoi(int ngay_sinh, int thang_sinh, int nam_sinh) {
	    time_t baygio;
	    struct tm *thoigian;
	    int tuoi;
	    
	    // Lấy thời gian hiện tại
	    baygio = time(NULL);
	    thoigian = localtime(&baygio);
	
	    // Tính tuổi
	    tuoi = thoigian->tm_year + 1900 - nam_sinh;
	
	    // Kiểm tra xem đã qua sinh nhật chưa
	    if (thang_sinh > (thoigian->tm_mon + 1) || (thang_sinh == (thoigian->tm_mon + 1) && ngay_sinh > thoigian->tm_mday)) {
	        tuoi--;
	    }
	
	    return tuoi;
	}
	void display(Student head) {
	    Student current = head;
	    int stt = 1;
	
	    // Nếu danh sách không trống
	    if (head != NULL) {
	        printf("\x1b[38;2;255;215;0m%73s\x1b[38;2;255;255;255m", "DANH SACH SINH VIEN\n");
	        printf("\x1b[38;2;255;255;255m");
	        for (int i = 0; i < 132; i++) printf("-");
	        printf("\n");
	        printf("|\x1b[38;2;255;215;0mSTT\x1b[38;2;255;255;255m| ID |         \x1b[38;2;255;215;0mTen\x1b[38;2;255;255;255m         |  Lop  | Gioi | NgaySinh | \x1b[38;2;124;252;0mToan\x1b[38;2;255;255;255m | \x1b[38;2;124;252;0mLy\x1b[38;2;255;255;255m  | \x1b[38;2;124;252;0mTin\x1b[38;2;255;255;255m |  \x1b[38;2;225;105;180mTB\x1b[38;2;255;255;255m   |  \x1b[38;2;225;105;180mHB\x1b[38;2;255;255;255m  |   Dia Chi   |           \x1b[38;2;0;255;255mEmail\x1b[38;2;255;255;255m          |\n");
	        for (int i = 0; i < 132; i++) printf("-");
	        do {
	            printf("\n| \x1b[38;2;255;215;0m%-2d\x1b[38;2;255;255;255m| %-3d| \x1b[38;2;255;215;0m%-20s\x1b[38;2;255;255;255m|%-7s| %-5s|%-2d/%-2d/%-4d|\x1b[38;2;124;252;0m%-6.2f\x1b[38;2;255;255;255m|\x1b[38;2;124;252;0m%-5.2f\x1b[38;2;255;255;255m|\x1b[38;2;124;252;0m%-5.2f\x1b[38;2;255;255;255m| \x1b[38;2;225;105;180m%-5.2f\x1b[38;2;255;255;255m | \x1b[38;2;225;105;180m%-3d\x1b[38;2;255;255;255m  | %-12s| \x1b[38;2;0;255;255m%-24s\x1b[38;2;255;255;255m|\n",
	                   stt, current->student.ID, current->student.name, current->student.lop, current->student.gioitinh,
	                   current->birth.day, current->birth.month, current->birth.year, current->diem.toan, current->diem.ly, current->diem.tin, current->diem.trungbinh,
	                   current->diem.hocbong, current->student.diachi, current->student.email);
	            for (int i = 0; i < 132; i++) printf("-");
	            current = current->next;
	            stt++;
	        } while (current != head);
	    } else {
	        printf("\x1b[38;2;255;0;0m%73s\x1b[38;2;255;255;255m", "---------DANH SACH RONG--------\n");
	        printf("\x1b[38;2;255;215;0m%73s\x1b[38;2;255;255;255m","   Vui long them du lieu sinh vien ! \n");
	    }
	    printf("\n");
	}
	
	void insv(Student current, int stt) {
		if (!tieude){
			for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	    	printf("|\x1b[38;2;255;215;0mSTT\x1b[38;2;255;255;255m| ID |         \x1b[38;2;255;215;0mTen\x1b[38;2;255;255;255m         |  Lop  | Gioi | NgaySinh | \x1b[38;2;124;252;0mToan\x1b[38;2;255;255;255m | \x1b[38;2;124;252;0mLy\x1b[38;2;255;255;255m  | \x1b[38;2;124;252;0mTin\x1b[38;2;255;255;255m |  \x1b[38;2;225;105;180mTB\x1b[38;2;255;255;255m   |  \x1b[38;2;225;105;180mHB\x1b[38;2;255;255;255m  |   Dia Chi   |           \x1b[38;2;0;255;255mEmail\x1b[38;2;255;255;255m         |\n");
	       for (int i=0 ; i<132; i++) printf("-");
	       tieude=1;
		}
	    // Nếu danh sách không trống
	            printf("\n| \x1b[38;2;255;215;0m%-2d\x1b[38;2;255;255;255m| %-3d| \x1b[38;2;255;215;0m%-20s\x1b[38;2;255;255;255m|%-7s| %-5s|%-2d/%-2d/%-4d|\x1b[38;2;124;252;0m%-6.2f\x1b[38;2;255;255;255m|\x1b[38;2;124;252;0m%-5.2f\x1b[38;2;255;255;255m|\x1b[38;2;124;252;0m%-5.2f\x1b[38;2;255;255;255m| \x1b[38;2;225;105;180m%-5.2f\x1b[38;2;255;255;255m | \x1b[38;2;225;105;180m%-3d\x1b[38;2;255;255;255m  | %-12s| \x1b[38;2;0;255;255m%-24s\x1b[38;2;255;255;255m|\n",
	                   stt, current->student.ID, current->student.name, current->student.lop, current->student.gioitinh,
	                   current->birth.day,current->birth.month,current->birth.year,current->diem.toan,current->diem.ly,current->diem.tin,current->diem.trungbinh,
	                   current->diem.hocbong, current->student.diachi, current->student.email);
	                    for (int i=0 ; i<132; i++) printf("-");
	            current = current->next;
	    }
	//ham kiem tra nhap diem
	void nhapdiem(float *diem,char *monhoc){
	    float tmp;
		do {
	        printf("Nhap diem %s (0 <= diem <= 10): ",monhoc);
	        scanf("%f", &tmp);
	        
	        if (tmp < 0 || tmp > 10) {
	            printf("Diem nhap vao khong hop le. Vui long nhap lai!\n");
	        }
	    } while (tmp < 0 || tmp > 10);
	    *diem=tmp;
	}
	void menu(){
		printf("                                                  \x1b[38;2;255;215;0m%s\x1b[38;2;255;255;255m","----------MENU-----------\n");
	        printf("| 1. In danh sach sinh vien  \n");
	        printf("| 2. Them sinh vien vao danh sach ( cuoi danh sach) .\n");
	        printf("| 3. Tim kiem   .\n");
	        printf("| 4. Xoa sinh vien ( theo ID ) .\n");
	        printf("| 5. Chinh sua thong tin sinh vien \n");//
	        printf("| 6. Sap xep danh sach sinh vien .\n");
	        printf("| 7. Chen mau tin tai vi tri bat ki \n");//
	        printf("| 8. Chen mau tin sao cho danh sach van sap xep theo thu tu chu cai ten cua ho (cung ten sap xep theo tuoi )\n");//
	        printf("| 9. Thong ke \n");//
	        printf("| 10. Xoa cac ban nu khoa 08 \n");//
	        printf("| 11. Doc file du lieu \n"); 
	        printf("| 0. Ket thuc chuong trinh !\n");
	    }
	void chuanhoaten(char *name) {
	    int len = strlen(name);
	    name[0] = toupper(name[0]);
	    // Duyệt qua các ký tự còn lại trong tên
	    for (int i = 1; i < len; i++) {
	        if (name[i] == ' ' && islower(name[i + 1])) {
	            name[i + 1] = toupper(name[i + 1]);
	        }
	    }
	}
	//tao node moi tu node
	Student createNode(struct element info,struct datascore diem,struct databirth birth) {
	    Student newstudent = malloc(sizeof(struct Node));
	    // Sao chép dữ liệu vào nút mới
	    strcpy(newstudent->student.name, info.name);
	    newstudent->student.age= info.age;
	    strcpy(newstudent->student.diachi, info.diachi);
	    strcpy(newstudent->student.gioitinh, info.gioitinh);
	     newstudent->student.ID=info.ID;
	    strcpy(newstudent->student.khoa, info.khoa);
	    strcpy(newstudent->student.lop, info.lop);   
	    strcpy(newstudent->student.email, info.email);   
	    newstudent->diem=diem;
	    newstudent->birth=birth;
	    // Thiết lập con trỏ next và prev của nút mới là NULL ban đầu
	    newstudent->next = NULL;
	    newstudent->prev = NULL;
	    
	    return newstudent; // Trả về con trỏ tới nút mới được trả về 
	}
	void docfile(const char *filename, Student *head) {
	    FILE *f = fopen(filename, "r");
	    if (f == NULL) {
	        printf("Khong the mo tep %s \n", filename);
	        return;
	    }
	
	    char tmp[100]; // Dùng để đọc từng dòng từ tệp
	    int dong=0;
	    int kiemtrafile=1;
	    // Đọc dữ liệu sinh viên từ file
	    while (fgets(tmp, sizeof(tmp), f) != NULL) {
	    	dong++;
			int dem=0;
	        // Tạo một nút mới để chứa thông tin của sinh viên từ dòng hiện tại
	        Student newnode = (struct Node*)malloc(sizeof(struct Node));
	        if (newnode == NULL) {
	            printf("Khong du bo nho de tao sinh vien moi.\n");
	            fclose(f);
	            return;
	        }
	        // Tách các trường từ chuỗi đọc được từ file
	        char* token = strtok(tmp, ",");
	        if (token != NULL) {
	            // Lưu tên sinh viên vào cấu trúc
	          //sau khi lấy ra thì sẽ tồn tại " " ở cuối chuỗi để so sánh thì ta phải loại bỏ nó
	            chuanhoaten(token);
	            strncpy(newnode->student.name, token, sizeof(newnode->student.name));
	            dem++;
	        }
	        //ID
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	           newnode->student.ID=atoi(token);
	           ID[newnode->student.ID]=1;
	           dem++;
	        }
	        // Tiếp tục đọc các trường và lưu vào cấu trúc sinh viên
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	            // Lưu tuổi sinh viên vào cấu trúc
	           dem++;
			   newnode->birth.day=atoi(token);
	        }
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	            // Lưu tuổi sinh viên vào cấu trúc
	          dem++;
			   newnode->birth.month=atoi(token);
	        }
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	            // Lưu tuổi sinh viên vào cấu trúc
	           dem++;
			   newnode->birth.year=atoi(token);
	        }   
	        //them vao cuoi danh sach double cirlator
			token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
				chuanhoaten(token);
	        	strncpy(newnode->student.gioitinh, token, sizeof(newnode->student.gioitinh));
	        }
	        	token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
				strncpy(newnode->student.diachi, token, sizeof(newnode->student.diachi));
	        }
	        	token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
				strncpy(newnode->student.email, token, sizeof(newnode->student.email));
	        }
	        	token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
	        	strncpy(newnode->student.lop, token, sizeof(newnode->student.lop));
	        }
	        	token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
				strncpy(newnode->student.khoa, token, sizeof(newnode->student.khoa));
	        }
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
				newnode->diem.toan=atof(token);
	        }
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	        	dem++;
				newnode->diem.ly=atof(token);
	        }
	        token = strtok(NULL, ",");
	        if (token != NULL) {
	           dem++;        
				newnode->diem.tin=atof(token);
	        }
	        if(dem!=13){
	        	printf(" \x1b[38;2;255;0;0mDong %d : Du lieu khong chinh xac , vui long kiem tra lai !\x1b[38;2;255;255;255m\n",dong);
	        	kiemtrafile=0;
			}
	        newnode->diem.trungbinh=(newnode->diem.ly+newnode->diem.toan+newnode->diem.tin)/3;
	        newnode->diem.hocbong=hocbong(newnode);
	        newnode->student.age=tinh_tuoi(newnode->birth.day,newnode->birth.month,newnode->birth.year);
	         if(*head==NULL){
	        	*head=newnode;
	        	newnode->next=newnode;
	            newnode->prev=newnode;//tao thanh 1 vong lien ket
			}
			else {
				Student last=(*head)->prev;
				newnode->next=*head;
				newnode->prev=last;
				last->next=newnode;
				(*head)->prev = newnode;
			}
	    }
	   if(kiemtrafile==1){ 
	    display(*head);
	    printf("\x1b[38;2;255;215;0m%84s\x1b[38;2;255;255;255m","Lay du lieu sinh vien thanh cong ! \n.");
	}
	   else {
	   	memset(ID,0,sizeof(ID));
		*head=NULL;
	   	printf("\x1b[38;2;255;215;0m%84s\x1b[38;2;255;255;255m","Lay du lieu sinh vien khong thanh cong ! \n.");
	   }
	    fclose(f);
	}
	
	
	// Hàm ghi nội dung danh sách vào file
	void ghifile(Student head, const char *filename) {
		if (head==NULL) return ;
	 FILE *f = fopen(filename, "w");
		Student student=head;
		do{
	        fprintf(f,"%s,%d,%d,%d,%d,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f\n",
	                student->student.name, student->student.ID, student->birth.day,
	                student->birth.month, student->birth.year, student->student.gioitinh,
	               student->student.diachi,student->student.email, student->student.lop,
	                student->student.khoa, student->diem.toan, student->diem.ly, student->diem.tin);
	        student = student->next;
	    }
	    while(student!=head);
	    fclose(f);
	}
	void add(Student *head) {
	    Student newstudent = malloc(sizeof(struct Node));
	    if (newstudent == NULL) {
	        printf("Khong du bo nho !\n");
	        return;
	    }
	  int tmp;
	  int dem=1;
	  do{
	  	if (dem==4){
	       printf("Default ! \n");
	       return;
		  }
		printf("Nhap ID :"); 
	  	dem++;
	  	scanf("%d",&tmp);
	  	if (ID[tmp]==1) printf("ID bi trung !\n");
	  }
	  while(ID[tmp]==1);
	  ID[tmp]=1;
	   printf("Nhap ho va ten :");
	    getchar();
	    fgets(newstudent->student.name, sizeof(newstudent->student.name), stdin);
	  newstudent->student.name[strcspn(newstudent->student.name, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	  chuanhoaten(newstudent->student.name);
	  newstudent->student.ID=tmp;
	    printf("Nhap ngay thang nam sinh (VD :19 4 2005) :");
	    scanf("%d%d%d",&newstudent->birth.day,&newstudent->birth.month,&newstudent->birth.year);
		 printf("Gioi Tinh : 1 - Nam   0 - Nu\nChon:");
		int tmp1;
		do{
	     scanf("%d",&tmp1);
	     if (tmp1==1) strcpy(newstudent->student.gioitinh,"Nam");
	     else if (tmp1==0) strcpy(newstudent->student.gioitinh,"Nu");
	     else printf("Chon lai gioi tinh :");
	 }
	 while(tmp1!=1&&tmp1!=0);
	 printf("Khoa : 1.CNTT(Cong nghe thong tin )\t2.Tu dong hoa(TDH)\t3.Co dien tu(CDT)\t4.Dien tu vien thong(DTVT)\n");
	 int tmp2;
	 do{
	     scanf("%d",&tmp2);
	     if (tmp2==1) strcpy(newstudent->student.khoa,"CNTT");
	     else if (tmp2==2) strcpy(newstudent->student.khoa,"TDH");
	     else if (tmp2==3) strcpy(newstudent->student.khoa,"CDT");
	     else if (tmp2==4) strcpy(newstudent->student.khoa,"DTVT");
	     else printf("Chon lai khoa(1-2-3-4) :");
	 }
	 while(tmp2!=1&&tmp2!=2&&tmp2!=3&&tmp2!=4);
	 int tmp3;
	char result[20];
	 int nienkhoa;
	 printf("Nien Khoa :"); 
	scanf("%d",&nienkhoa);
	if(nienkhoa>=10){
	      printf("Khoa %s - lop : 1.%d%s1\t2.%d%s2\t\t3.%d%s3\n",newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa);
	      do{
	     scanf("%d",&tmp3);
	if (tmp3==1) {sprintf(result, "%d%s1",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==2) {sprintf(result, "%d%s2",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==3) {sprintf(result, "%d%s3",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	  else printf("Chon lai khoa(1-2-3) :");
	 }while(tmp3!=1&&tmp3!=2&&tmp3!=3);
	}
	else {
		 printf("Khoa %s - lop : 1.0%d%s1\t2.0%d%s2\t\t3.0%d%s3\n",newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa);
	      do{
	     scanf("%d",&tmp3);
	if (tmp3==1) {sprintf(result, "0%d%s1",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==2) {sprintf(result, "0%d%s2",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==3) {sprintf(result, "0%d%s3",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	  else printf("Chon lai khoa(1-2-3) :");
	 }while(tmp3!=1&&tmp3!=2&&tmp3!=3);
	}
	       printf("Dia chi :");
	        getchar();
	        fgets(newstudent->student.diachi, sizeof(newstudent->student.diachi),stdin);
	         newstudent->student.diachi[strcspn(newstudent->student.diachi, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	         chuanhoaten(newstudent->student.diachi);
	        printf("Email (VD: huan->huan@gmail.com) :");
	        char tmp4[20];
	        scanf("%s",tmp4);
	        strcat(tmp4,"@gmail.com");
	        strcpy(newstudent->student.email,tmp4);
	        printf("----->%s\n",tmp4);
	          nhapdiem(&newstudent->diem.toan,"Toan");
	  nhapdiem(&newstudent->diem.ly,"Ly");
	     nhapdiem(&newstudent->diem.tin,"Tin");
	   
	       newstudent->diem.trungbinh=(newstudent->diem.ly+newstudent->diem.toan+newstudent->diem.tin)/3;
	        newstudent->diem.hocbong=hocbong(newstudent);
	        newstudent->student.age=tinh_tuoi(newstudent->birth.day,newstudent->birth.month,newstudent->birth.year);
	       //bo sung cau lenh xuat ra sinh vien ban vua them vao danh sach
	    if (*head==NULL) {
	    	*head=newstudent;
	    	newstudent->next=newstudent;
	    	newstudent->prev=newstudent;
		}
		else {
		Student last=(*head)->prev;
		newstudent->next=*head;
		newstudent->prev=last;
		last->next=newstudent;
		(*head)->prev=newstudent;
		}
		free(newstudent);
		Student current=(*head)->prev;
	insv(current,1);
	    printf("                                                   \x1b[38;2;255;215;0m%s\x1b[38;2;255;255;255m","-----Them sinh vien thanh cong !-----\n");
	tieude=0;
	}  
	
	//ham so sanh ten 
	int sosanh(char* name1, char* name2) {
	    int len1 = strlen(name1) - 1;
	    int len2 = strlen(name2) - 1;
	    // Tìm vị trí của ký tự khoảng trắng cuối cùng trong mỗi chuỗi
	    while (len1 >= 0 && len2 >= 0) {
	        while (len1 >= 0 && name1[len1] != ' ') {
	            len1--;
	        }
	        while (len2 >= 0 && name2[len2] != ' ') {
	            len2--;
	        }
	        // So sánh phần sau ký tự khoảng trắng cuối cùng
	        int result = strcmp(name1 + len1 + 1, name2 + len2 + 1);
	       if (result>0) return 1;
	       if(result<0) return 0;
	       len1--;
	        len2--;
	      }
	    return 0;
	}
	
	
	
	//Tim kiem sinh vien
	void namefullsearch(Student head, char searchName[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	    do {
	        if (strcmp(current->student.name, searchName) == 0) {
		   insv(current,count);
				found = 1;
				count++;
	        }
	        current = current->next;
	    }
	        while (current!=head);
	        printf("\n");
	    if (!found) {
	        printf("----Khong tim thay sinh vien  %s----\n", searchName);
	    }
	    tieude=0;
	}
	void namesearch(Student head, char searchName[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    chuanhoaten(searchName);
	    printf("Ket qua tim kiem :\n");
	    do {
	    	int tmp5=strlen(current->student.name);
	    while(tmp5>=0&&current->student.name[tmp5]!=' '){
	    	tmp5--;
		}
	        if (strcmp(current->student.name+tmp5+1, searchName) == 0) {
		   insv(current,count);
		   count++;
				found = 1;
	        }
	        current = current->next;
	    }
	        while (current!=head);
	    if (!found) {
	        printf("----Khong tim thay sinh vien  %s----\n", searchName);
	    }
	    tieude=0;
	}
	//------------------------------------------
	//ham tim kien bang tuoi
	void agesearch(Student head, int Sage) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    int tieude=0;
	    printf("Ket qua tim kiem :\n");
	do {
	        if (current->student.age== Sage) {
	          insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
			while (current!=head);
	    if (!found) {
	        printf("Khong tim thay sinh vien do tuoi :  %d\n",Sage );
	    }
	    tieude=0;
	}
	//tim kiem bang ID
	void IDsearch(Student head, int SID) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	    do {
	        if (current->student.ID==SID) {
	        insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while (current!=head);
	    if (!found) {
	        printf("Khong tim thay sinh vien lop :  %s\n",Slop );
	    }
	    tieude=0;
	}
	//------------------------------------------
	void lopsearch(Student head, char Slop[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	    do {
	        if (strcmp(current->student.lop,Slop)==0) {
	         insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	    }
	   while (current!=head);
	    if (!found) {
	        printf("Khong tim thay sinh vien lop :  %s\n",Slop );
	    }
	    tieude=0;
	}
	//tim kiem sinh vien theo khoa 
	void khoasearch(Student head, char Skhoa[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	    do{
	        if (strcmp(current->student.khoa,Skhoa)==0) {
	      insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	    }
	   while (current!=head);
	    if (!found) {
	        printf("Khong tim thay sinh vien khoa :  %s\n",Skhoa );
	    }
	    tieude=0;
	}
	//tim kiem sinh vien theo gioi tinh
	void gioitinhsearch(Student head, char Sgioitinh[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	     printf("\n");
	    	printf("|STT| ID |         Ten         |  Lop  | Gioi | NgaySinh |Toan | Ly  | Tin |  TB  |  HB  |   Dia Chi   |           Email           |\n");
	       for (int i=0 ; i<132; i++) printf("-");
	    do {
	        if (strcmp(current->student.gioitinh,Sgioitinh)==0) {
	      insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while (current!=head);
	    if (!found) {
	        printf("Khong tim thay sinh vien gioitinh :%s\n",Sgioitinh );
	    }
	    tieude=0;
	}
	//tim kiem sinh vien theo diachi
	void diachisearch(Student head, char Sdiachi[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	  do{
	  	 if (strcmp(current->student.diachi,Sdiachi)==0) {
	 insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while(current!=head);
	    printf("\n");
	    if (!found) {
	        printf("Khong tim thay sinh vien lop :  %s\n",Sdiachi );
	    }
	    tieude=0;
	}
	//tim kiem sinh vien theo email
	void emailsearch(Student head, char Semail[50]) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	    do {
	        if (strcmp(current->student.email,Semail)==0) {
	       insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while (current!=head);
	    if (!found) {
	        printf("Khong tim thay sinh vien lop :  %s\n",Semail );
	    }
	    tieude=0;
	}
	void infosearch(Student head){//tim kiem theo thong tin ca nhan
		int select;
	printf(" \x1b[38;2;255;215;0mTIM KIEM \x1b[38;2;255;255;255m  : \n");
	        printf(" 1.Ho va ten sinh vien \n");
	        printf(" 2.Ten sinh vien \n");
			printf(" 3.Tuoi sinh vien \n");
			printf(" 4.ID sinh vien \n");
			printf(" 5.Khoa cua sinh vien \n");
			printf(" 6.lop sinh vien \n");		
			printf(" 7.Dia chi \n");
			printf(" 8.Email \n");
			printf(" 9.Gioi tinh \n");
			printf(" 0.Thoat !\n");
			printf("--------------------------------\n");
	    printf(" \x1b[38;2;255;215;255mNhap lua chon tim kiem theo thong tin ca nhan\x1b[38;2;255;255;255m  : ");
	  scanf("%d", &select);
	switch (select) {
	   case 1: //tim kiem theo ten 
	   printf("Nhap ho va ten :");
	   getchar();
	    fgets(Sfullname,sizeof(Sfullname), stdin);
	    Sfullname[strcspn(Sfullname, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	    chuanhoaten(Sfullname);
	   namefullsearch(head,Sfullname) ;
	   printf("\n");
	   return;
	   case 2://tim kiem theo ten
	   printf("Nhap Ten :");
	   getchar();
	    scanf("%s",Sname);
	   namesearch(head,Sname) ;
	   printf("\n");
	   return;
	   case 3: //tim kiem theo tuoi
	   printf("Nhap tuoi sinh vien can tim kiem : ");
	   scanf("%d",&Sage);
	   agesearch( head, Sage);
	   printf("\n");
	   return;
	   case 4://tim kiem theo ID
	   printf("Nhap ID sinh vien can tim kiem : ");
	   scanf("%d",&SID);
	   IDsearch(head,SID);
	   printf("\n");
	   return;
	   case 5://tim kiem theo khoa
	   printf("Nhap khoa sinh vien can tim kiem : \n1-Cong nghe thong tin\t2-Tu dong hoa\t3-Co dien tu\t4-Dien tu vien thong\n");
	 int tmp1;
	 printf("Chon :");
	 scanf("%d",&tmp1);
	 if (tmp1==1) khoasearch(head,"CNTT");
	 else  if (tmp1==2) khoasearch(head,"TDH");
	 else  if (tmp1==3) khoasearch(head,"CDT");
	 else  if (tmp1==4) khoasearch(head,"DTVT");
	 else printf("Khong tim thay sinh vien nhu yeu cau !");
	   printf("\n");
	   return;
	   case 6://tim kiem theo lop
	   printf("Tim kiem theo lop :");
	   scanf("%s",Slop);
	   lopsearch(head,Slop);
	   printf("\n");
	   return;
	   case 8://tim kiem theo email
	   printf("Email (VD: huan->huan@gmail.com) :");
	        scanf("%s",Semail);
	        strcat(Semail,"@gmail.com");
	        printf("----->%s\n",Semail);
	   emailsearch(head,Semail);
	   printf("\n");
	   return;
	   case 7://tim kiem theo diachi
	   printf("Nhap dia chi sinh vien can tim kiem : ");
	   getchar();
	   fgets(Sdiachi , sizeof(Sdiachi ), stdin);
	   Sdiachi[strcspn(Sdiachi,"\n")]='\0';
	   diachisearch(head,Sdiachi);
	   printf("\n");
	   return;
	   case 9://tim kiem theo gioitinh
	   printf("Nhap gioi tinh sinh vien can tim kiem :\n 1-Nam\t0-Nu \n");
	   int tmp2;
	   printf("Chon :"); scanf("%d",&tmp2);
	   if (tmp2==1) gioitinhsearch(head,"Nam");
	   else if (tmp2==0) gioitinhsearch(head,"Nu");
	   else printf("Khong tim thay sinh vien nhu yeu cau ! ");
	   printf("\n");
	   return;
	   case 0:
	   	printf("Ket thuc.\n");
	   	break;
	   	default :
	   		printf("Lua chon khong hop le . Vui long nhap lai : \n");
	   }
	}
	void toansearch(Student head, float diem) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	  do{
	  	 if (fabs(current->diem.toan -diem)<esp){
	  insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while(current!=head);
	    printf("\n");
	    if (!found) {
	        printf("Khong tim thay sinh vien ! : \n" );
	    }
	    tieude=0;
	}
	
	void lysearch(Student head, float diem) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	  do{
	  	 if (fabs(current->diem.ly -diem)<esp){
	  insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while(current!=head);
	    printf("\n");
	    if (!found) {
	        printf("Khong tim thay sinh vien ! :  %s\n");
	    }
	    tieude=0;
	}
	
	void tinsearch(Student head, float diem) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	  do{
	  	 if (fabs(current->diem.tin-diem)<esp){
	 insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while(current!=head);
	    printf("\n");
	    if (!found) {
	        printf("Khong tim thay sinh vien ! :  %s\n" );
	    }
	    tieude=0;
	}
	
	void dtbsearch(Student head, float diem) {
	    Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	  do{
	  	 if (fabs(current->diem.trungbinh -diem)<esp){
	  	 insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while(current!=head);
	    printf("\n");
	    if (!found) {
	        printf("Khong tim thay sinh vien ! : \n" );
	    }
	    tieude=0;
	}
	
	void scoresearch(Student head){//tim kiem theo diem
		int select;
	printf(" \x1b[38;2;255;215;0mTIM KIEM \x1b[38;2;255;255;255m : \n");
	printf("  TIM KIEM : \n");
	printf("  1. Toan \n");
	printf("  2. Ly \n");
	printf("  3. Tin\n");
	printf("  4. Diem trung binh \n");
	printf("  0.Thoat.\n");
	printf("----------------------------------\n");
	printf(" \x1b[38;2;255;215;255mLua chon tim kiem theo diem : \x1b[38;2;255;255;255m");
	do{
		scanf("%d",&select);
		switch(select){
			case 1://theo diem toan
			nhapdiem(&Stoan,"Toan");
			toansearch(head,Stoan);
		    return;
			case 2://theo diem ly
			nhapdiem(&Sly,"Ly");
			lysearch(head,Sly);
			return;
			case 3://theo diem tin
			nhapdiem(&Stin,"Tin");
			tinsearch(head,Stin);
		    return;
			case 4://theo diem trung binh
			nhapdiem(&Strungbinh,"Trung Binh ");
			dtbsearch(head,Strungbinh);
			return;
			case 0: 
			printf("Thoat !\n");
			break;
			default: 
			printf("Lua chon khong hop le , vui long chon lai !");
		}
	}
	while(select!=0);
	}
	void hocbongsearch(Student head, int muc){
		Student current = head;
	    int found = 0;
	    int count=1;
	    printf("Ket qua tim kiem :\n");
	  do{
	  	 if (current->diem.hocbong ==muc){
	  	 insv(current,count);
				found = 1;
				count++;
		   }
	        current = current->next;
	        }
	   while(current!=head);
	    printf("\n");
	    if (!found) {
	        printf("Khong tim thay sinh vien !\n" );
	}
	tieude=0;
	}
	void scholarship(Student head){
		int select;
	printf(" \x1b[38;2;255;215;255mTIM KIEM : \x1b[38;2;255;255;255m \n");
	printf("1. Sinh vien hoc bong 200 .\n");
	printf("2. Sinh vien hoc bong 100 .\n");
	printf("Chon :");
	do{
		scanf("%d",&select);
		if (select!=1&&select!=2) printf("Lua chon khong hop le . vui long nhap lai lua chon :");
	}
	while(select!=1&&select!=2);
	if (select==1) hocbongsearch(head,200);
	else hocbongsearch(head,100);
	}
	
	void search(Student head){
		int select;
	do{
		printf("Tim kiem :  1.Thong tin ca nhan\t2.Thong tin diem\t3.Hoc bong\t0.Ket thuc !\n");
	  printf("Tim kiem theo tieu chi  : ");
	  scanf("%d", &select);
	switch (select) {
		case 1://thong tin ca nhan
		infosearch(head);
		break;
		case 2://tim kiem theo diem
		scoresearch(head);
		break;
		case 3: //tim kiem theo hoc bong
		scholarship(head);
		break;
		case 0:
	   	printf("                -------------------------------Ket thuc viec tin kiem thong tin sinh vien !  ----------------------------\n");
	   	break;
	   	default :
	   		printf("Nhap lai lua chon : \n");
	   }
	}
	   while (select != 0);
	   printf("\n");
	}
	//ham tim sinh vien có ID de delete
	Student find(Student head, int  FID) {
	Student tmp=head;
	do{
		if(tmp->student.ID==FID) {
			return tmp;
		}
	tmp=tmp->next;
	}
	while(tmp!=head);
	 return NULL;
	}
	
	void deleteNode(Student * head, unsigned long DID) {
	    if (*head == NULL)
	        return;
	
	    Student current = *head;
	    Student tmp = NULL;
	
	    // Nếu nút cần xóa là nút đầu tiên của danh sách
	    if (current->student.ID ==DID ) {
	        (*head) = current->next;
	        current->prev->next=*head;
	        (*head)->prev = current->prev;
	        printf("                  -------------------------------Sinh vien ban vua xoa !  ----------------------------\n");
		insv(current,1);
	        free(tmp);
	        return;
	    }
	    // Duyệt danh sách để tìm nút cần xóa
	    tmp=find(current,DID);
	    if (tmp!=NULL){// tim thay node can xoa 
	    if (tmp->next!=*head){//khong phai node cuoi cung cua danh sach
	    tmp->next->prev=tmp->prev;
	    tmp->prev->next = tmp->next;
	}
	// Nếu nút cần xóa là nút cuối cùng của danh sách
	     else{
		   tmp->prev->next = (*head);
	        (*head)->prev = tmp->prev;
	    }
	        printf("Ban vua xoa sinh vien co ID: %d ra khoi danh sach !\n",DID);
	        insv(tmp,1);
	       free(tmp); 
	    ID[DID]=0;
	    return;
	    }
	else {
	    // Nếu nút không tồn tại trong danh sách
	    printf("Khong tim thay sinh vien co ID = %ld \n",DID);
	}
	tieude=0;
	}
	void editname(Student tmp, char Ename[50]){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua ho va ten sinh vien %s ---> %s\x1b[38;2;255;255;255m \n ",tmp->student.name,Ename);
		       strcpy( tmp->student.name,Ename);
		       tieude=0;
		       insv(tmp,1);
		       tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editage(Student tmp , int day, int month, int year){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua  sinh vien co ngay/thang/nam sinh : %d/%d/%d ---> %d/%d/%d\x1b[38;2;255;255;255m \n ",tmp->birth.day,tmp->birth.month,tmp->birth.year,day,month,year);
		        tmp->birth.day=day;
		        tmp->birth.month=month;
		        tmp->birth.year=year;
		        insv(tmp,1);
		        tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editID(Student tmp, unsigned long EID){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua sinh vien ID: %d ---> ID: %d\x1b[38;2;255;255;255m \n ",tmp->student.ID,EID);
		        tmp->student.ID=EID;
		        insv(tmp,1);
		        tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editlop(Student tmp ,char Elop[50] ){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua sinh vien lop %s ---> %s\x1b[38;2;255;255;255m \n ",tmp->student.lop,Elop);
		       strcpy( tmp->student.lop,Elop);
		        insv(tmp,1);
		        tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editkhoa(Student tmp ,char Ekhoa[50] ){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua sinh vien khoa: %s ---> %s\x1b[38;2;255;255;255m \n ",tmp->student.khoa,Ekhoa);
		 strcpy( tmp->student.khoa,Ekhoa);
		        insv(tmp,1);
		        tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editgioitinh(Student tmp ,char Egioitinh[50] ){
		 strcpy(tmp->student.gioitinh,Egioitinh);
		        insv(tmp,1);
		        tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editdiachi(Student tmp ,char Ediachi[50] ){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua sinh vien co dia chi : %s ---> %s\x1b[38;2;255;255;255m \n ",tmp->student.diachi,Ediachi);
		 strcpy( tmp->student.diachi,Ediachi);
		       insv(tmp,1);
		       tieude=0;
		       printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editemail(Student tmp ,char Eemail[50] ){
		printf("\x1b[38;2;0;255;255mBan vua chinh sua ho va ten sinh vien %s ---> %s\x1b[38;2;255;255;255m \n ",tmp->student.name,Ename);
		strcpy( tmp->student.email,Eemail);
		        insv(tmp,1);
		        tieude=0;
		        printf("                             \x1b[38;2;255;215;0m----------------Chinh sua thong tin thanh cong ! ------------------\x1b[38;2;255;255;255m\n");
	}
	void editstudent(Student *head, int EDS){
		int option;
		Student current=*head;
		Student tmp=find(current, EDS);
		if (tmp!=NULL) {//tim ra sinh vien co ID can xoa
		printf(" CHINH SUA :\n");
			printf("1. Ho va ten \n");
			printf("2. Ngay/Thang/Nam sinh \n");
			printf("3. ID \n");
			printf("4. Lop \n");		
			printf("5. Khoa \n");
			printf("6. Dia chi \n");
			printf("7. Email \n");
			printf("8. Gioi tinh \n");
			printf("0. Thoat. \n");
			printf("--------------------------------\n");
		do{
			printf("Chinh thua thong tin ca nhan sinh vien %s - nhap lua chon :",tmp->student.name);
		      scanf("%d",&option);
			switch(option){
				case 1 ://chinh sua ten sinh vien
				printf("\x1b[38;2;0;255;255mNhap ho va ten moi cua sinh vien\x1b[38;2;255;255;255m :");
				getchar();
				fgets(Ename,50,stdin);
				chuanhoaten(Ename);
				Ename[strcspn(Ename, "\n")] = '\0';
				editname( tmp,Ename); 
				break;
		        case 2:
				 printf(" \x1b[38;2;0;255;255mNhap ngay thang nam moi cua sinh vien (VD : 1 1 2003)  :\x1b[38;2;255;255;255m"); scanf("%d%d%d",&Eday,&Emonth,&Eyear);
		        editage(tmp,Eday,Emonth,Eyear);
		        break;
		        case 3: 
		        printf(" \x1b[38;2;0;255;255mNhap Id moi cua sinh vien :\x1b[38;2;255;255;255m"); 
		        int IDtam;
				do{
				scanf("%d",&IDtam);
				if(ID[IDtam]==1) printf("ID bi trung ! Nhap lai ID :");
			}
			while(ID[IDtam]==1);
		        editID(tmp,IDtam);
		        break;	
				case 4: 
				printf(" \x1b[38;2;0;255;255mNhap Lop moi cua sinh vien\x1b[38;2;255;255;255m  :"); scanf("%s",Elop);
		        editlop(tmp,Elop);
		        break;
				case 5: 
				printf(" \x1b[38;2;0;255;255mNhap khoa moi cua sinh vien :\x1b[38;2;255;255;255m"); scanf("%s",Ekhoa);
		        editkhoa(tmp,Ekhoa);
		        break;
				case 6: 
				printf("\x1b[38;2;0;255;255mNhap dia chi moi cua sinh vien :\x1b[38;2;255;255;255m");
	        getchar();
	        fgets(Ediachi, sizeof(Ediachi),stdin);
	         Ediachi[strcspn(Ediachi, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	         chuanhoaten(Ediachi);
		        editdiachi(tmp,Ediachi);
		        break;    
				 case 7: 
				 printf("\x1b[38;2;0;255;255mNhap email cho sinh vien (huan--->huan@gmail.com):\x1b[38;2;255;255;255m");
	        scanf("%s",Eemail);
	        strcat(Eemail,"@gmail.com");
	        printf("----->%s\n",Eemail);
		        editemail(tmp,Eemail);
		        break;
		        case 8: 
		        if (strcmp(tmp->student.gioitinh,"Nam")==0){
		        		editgioitinh(tmp,"Nu");  
		        printf(" \x1b[38;2;0;255;255mBan vua chinh sua gioi tinh sinh vien : Nam ---> %s\x1b[38;2;255;255;255m \n",tmp->student.gioitinh);   
				}
		        else {
		        		editgioitinh(tmp,"Nam");
		        printf(" \x1b[38;2;0;255;255mBan vua chinh sua gioi tinh sinh vien : Nu ---> %s\x1b[38;2;255;255;255m \n",tmp->student.gioitinh);   
				}
		        break;
		        case 0:
	    printf("                            \x1b[38;2;255;215;0m----------------Ket thuc viec chinh sua thong tin sv ! ------------------.\x1b[38;2;255;255;255m\n");
	   	break;
	   	default:
	   		printf("Lua chon khong hop le ! \n");
			}
		}
		while(option!=0);
		}
		else printf("-->Khong tim thay sinh vien co ID: %d muon chinh sua !\n",EDS);
		}
		
	//arrange theo tuoi 
	void arrangeage(Student * listschool) {
	    if (*listschool == NULL || (*listschool)->next == (*listschool)) {
	        return;
	    }
	   struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current= *listschool;
	    do {
	         Student temp = current->next;
	        do {
	        	if (current->birth.year!=temp->birth.year){
	            if (current->birth.year<temp->birth.year) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
				}
				else {
					if(current->birth.month==temp->birth.month&&current->birth.day<temp->birth.day) {
				student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
				}
			    else if (current->birth.month<temp->birth.month){
	            student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
			}
				}
	            temp = temp->next;
	        } while (temp != *listschool);
	        current = current->next;
	    } while (current->next != *listschool);
	}
	// Sắp xếp danh sách sinh viên theo tên tăng dần
	void arrangename(Student * listschool) {
	    if (*listschool == NULL || (*listschool)->next == (*listschool)) {
	        return;
	    }
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student  current= *listschool;
	    do {
	         Student temp = current->next;
	        do {
	            if (sosanh(current->student.name,temp->student.name)) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *listschool);
	        current = current->next;
	    } while (current->next != *listschool);
	}
	//sap xep theo lop 
	void arrangeclass(Student * listschool){
		 if (*listschool == NULL || (*listschool)->next == (*listschool)) {
		 	printf("Vui long bo dung du lieu sinh vien !\n");
	        return;
	    }
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current= *listschool;
	    do {
	         Student temp = current->next;
	        do {
	            if (strcmp(current->student.lop+2,temp->student.lop+2)>0) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            else if (strcmp(current->student.lop+2,temp->student.lop+2)==0&&strncmp(current->student.lop,temp->student.lop,2)>0){
	            	student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
				}
	            temp = temp->next;
	        } while (temp != *listschool);
	        current = current->next;
	    } while (current->next != *listschool);
	}
	//sx theo khoa
	void arrangekhoa(Student * listschool){
		 if (*listschool == NULL || (*listschool)->next == (*listschool)) {
		 	printf("Vui long bo dung du lieu sinh vien !\n");
	        return;
	    }
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current= *listschool;
	    do {
	         Student temp = current->next;
	        do {
	            if (strcmp(current->student.khoa,temp->student.khoa)>0) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            else if (strcmp(current->student.khoa,temp->student.khoa)==0&&strcmp(current->student.khoa,temp->student.khoa)>0){
	            	student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
				}
	            temp = temp->next;
	        } while (temp != *listschool);
	        current = current->next;
	    } while (current->next != *listschool);
	}
	//sap xep theo ID
	void arrangeID(Student * listschool) {
	    if (*listschool == NULL || (*listschool)->next == (*listschool)) {
	        return;
	    }
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current= *listschool;
	    do {
	         Student temp = current->next;
	        do {
	            if (current->student.ID>temp->student.ID) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *listschool);
	        current = current->next;
	    } while (current->next != *listschool);
	}
	
	void sxdiemtoan(Student *head){
		if (*head==NULL){
			printf("Vui long bo sung du lieu sinh vien !\n");
			return;
		}
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current = current= *head;
	    do {
	         Student temp = current->next;
	        do {
	            if (current->diem.toan<temp->diem.toan) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *head);
	        current = current->next;
	    } while (current->next != *head);
	}
	
	void sxdiemly(Student *head){
		if (*head==NULL){
			printf("Vui long bo sung du lieu sinh vien !\n");
			return;
		}
	   struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current =current= *head;
	    do {
	         Student temp = current->next;
	        do {
	            if (current->diem.ly<temp->diem.ly) {
	            student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *head);
	        current = current->next;
	    } while (current->next != *head);
	}
	
	void sxdiemtin(Student *head){
		if (*head==NULL){
			printf("Vui long bo sung du lieu sinh vien !\n");
			return;
		}
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current =current= *head;
	    do {
	         Student temp = current->next;
	        do {
	            if (current->diem.tin<temp->diem.tin) {
	            student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *head);
	        current = current->next;
	    } while (current->next != *head);
	}
	void sxdiemhb(Student *head){
		if (*head==NULL){
			printf("Vui long bo sung du lieu sinh vien !\n");
			return;
		}
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current= *head;
	    do {
	         Student temp = current->next;
	        do {
	            if (current->diem.hocbong<temp->diem.hocbong) {
	            student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *head);
	        current = current->next;
	    } while (current->next != *head);
	}
	
	void sxdiemtb(Student *head){
		if (*head==NULL){
			printf("Vui long bo sung du lieu sinh vien !\n");
			return;
		}
	    struct element student;
		struct databirth birth;
	    struct datascore diem; 
	    Student current =  current= *head;
	    do {
	         Student temp = current->next;
	        do {
	            if (current->diem.trungbinh<temp->diem.trungbinh) {
	             student=current->student;
	             birth=current->birth;
	             diem=current->diem;
	             current->student=temp->student;
	             current->birth=temp->birth;
	             current->diem=temp->diem;
	            temp->student=student;
	            temp->birth=birth;
	            temp->diem=diem;
	            }
	            temp = temp->next;
	        } while (temp != *head);
	        current = current->next;
	    } while (current->next != *head);
	}
	void sxdiem(Student *head){
		int option;
		printf(" SAP XEP DIEM :\n");
		printf("1. Toan \n");
			printf("2. Ly \n");
				printf("3. Tin \n");
					printf("4. Diem trung binh \n");
						printf("5. Hoc bong \n");
						printf("0. Ket thuc sap xep diem !\n");
						do{
							printf("Nhap lua chon sap xep diem :"); scanf("%d",&option);
			switch(option){
				case 1: 
				sxdiemtoan(head);
				display(*head);
				return ;
				case 2 :
				sxdiemly(head);
				display(*head);
				return ;
			    case 3 :
				sxdiemtin(head);
				display(*head);
				return ;
				case 4:
				sxdiemtb(head);
				display(*head);
				return ;
				case 5:
				sxdiemhb(head);
				display(*head);
				return ;
				case 0:
					return;
				default:
					printf("Lua chon khong hop le ! \n");
			}
	}while(option!=0);
	}
	
	void sxnienkhoa(Student *head){
		if(*head==NULL){
			printf("Vui long bo sung du lieu sinh vien !\n");
		}
	    struct element e;
	    Student current= *head;
	    do {
	         Student temp = current->next;
	        do {
	            if (strncmp(current->student.lop,temp->student.lop,2)>0) {
	             e=current->student;
	             current->student=temp->student;
	            temp->student=e;
	            }
	            temp = temp->next;
	        } while (temp != *head);
	        current = current->next;
	    } while (current->next != *head);
	}
	void chenbatki(Student *head,int vitri ){
		int dem=1;
	Student newstudent = malloc(sizeof(struct Node));
	    if (newstudent == NULL) {
	        printf("Khong du bo nho !\n");
	        return;
	    }
	  printf("Nhap ID :"); 
	  int tmp;
	  do{
	  	scanf("%d",&tmp);
	  	if (ID[tmp]==1) printf("ID bi trung !\nNhap lai :");
	  }
	  while(ID[tmp]==1);
	  ID[tmp]=1;
	  newstudent->student.ID=tmp;
	   printf("Nhap ho va ten : ");
	    getchar();
	    fgets(newstudent->student.name, sizeof(newstudent->student.name), stdin);
	  newstudent->student.name[strcspn(newstudent->student.name, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	  chuanhoaten(newstudent->student.name);
	    printf("Nhap ngay thang nam sinh (VD :19 4 2005) :");
	    scanf("%d%d%d",&newstudent->birth.day,&newstudent->birth.month,&newstudent->birth.year);
		 printf("Gioi Tinh : 1 - Nam   0 - Nu\nChon:");
		int tmp1;
		do{
	     scanf("%d",&tmp1);
	     if (tmp1==1) strcpy(newstudent->student.gioitinh,"Nam");
	     else if (tmp1==0) strcpy(newstudent->student.gioitinh,"Nu");
	     else printf("Chon lai gioi tinh :");
	 }
	 while(tmp1!=1&&tmp1!=0);
	 printf("Khoa : 1.CNTT(Cong nghe thong tin )\t2.Tu dong hoa(TDH)\t3.Co dien tu(CDT)\t4.Dien tu vien thong(DTVT)\n");
	 int tmp2;
	 do{
	     scanf("%d",&tmp2);
	     if (tmp2==1) strcpy(newstudent->student.khoa,"CNTT");
	     else if (tmp2==2) strcpy(newstudent->student.khoa,"TDH");
	     else if (tmp2==3) strcpy(newstudent->student.khoa,"CDT");
	     else if (tmp2==4) strcpy(newstudent->student.khoa,"DTVT");
	     else printf("Chon lai khoa(1-2-3-4) :");
	 }
	 while(tmp2!=1&&tmp2!=2&&tmp2!=3&&tmp2!=4);
	 int tmp3;
	char result[20];
	 int nienkhoa;
	 printf("Nien Khoa :"); 
	scanf("%d",&nienkhoa);
	      printf("Khoa %s - lop : 1.%d%s1\t2.%d%s2\t\t3.%d%s3\n",newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa);
	      do{
	     scanf("%d",&tmp3);
	if (tmp3==1) {sprintf(result, "%d%s1",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==2) {sprintf(result, "%d%s2",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==3) {sprintf(result, "%d%s3",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	  else printf("Chon lai khoa(1-2-3) :");
	 }
	 while(tmp3!=1&&tmp3!=2&&tmp3!=3);
	       printf("Dia chi :");
	        getchar();
	        fgets(newstudent->student.diachi, sizeof(newstudent->student.diachi),stdin);
	         newstudent->student.diachi[strcspn(newstudent->student.diachi, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	         chuanhoaten(newstudent->student.diachi);
	        printf("Email (VD: huan->huan@gmail.com) :");
	        char tmp4[20];
	        scanf("%s",tmp4);
	        strcat(tmp4,"@gmail.com");
	        strcpy(newstudent->student.email,tmp4);
	        printf("----->%s\n",tmp4);
	         nhapdiem(&newstudent->diem.toan,"Toan");
	  nhapdiem(&newstudent->diem.ly,"Ly");
	     nhapdiem(&newstudent->diem.tin,"Tin");
	       newstudent->diem.trungbinh=(newstudent->diem.ly+newstudent->diem.toan+newstudent->diem.tin)/3;
	        newstudent->diem.hocbong=hocbong(newstudent);
	        newstudent->student.age=tinh_tuoi(newstudent->birth.day,newstudent->birth.month,newstudent->birth.year);
	       //bo sung cau lenh xuat ra sinh vien ban vua them vao danh sach
	    if (*head==NULL) {
	    	printf("                         \x1b[38;2;255;215;0mDanh sach rong , sinh vien ban vua them se o vi tri dau tien danh sach.\x1b[38;2;255;255;255m\n");
	    	*head=newstudent;
	    	newstudent->next=newstudent;
	    	newstudent->prev=newstudent;
	    	insv(newstudent,1);
	
	    	return;
		}
		else if (vitri==0||vitri==1){
			newstudent->next=(*head);
			newstudent->prev=(*head)->prev;
			newstudent->prev->next=newstudent;
			(*head)->prev=newstudent;
			*head=newstudent;
			insv(newstudent,1);
			return;
		}
		else {
			Student current = *head;
	        int i = 1;
	        while (i < vitri - 1 && current->next != *head) {
	            current = current->next;
	            i++;
	        }
	        // Chèn sinh viên mới vào vị trí được chỉ định
	      if(current->next!=*head){
		    newstudent->next = current->next;
	        current->next->prev=newstudent;
			current->next = newstudent;
			newstudent->prev=current;
			insv(newstudent,1);
			return;
		}
		else {//vi tri cuoi cung danh sach
		Student last=(*head)->prev;
		newstudent->next=*head;
		newstudent->prev=last;
		last->next=newstudent;
		(*head)->prev=newstudent;
	insv(newstudent,1);
	    printf("%77s","Them sinh vien thanh cong !\n");
		free(last);		
		}
		free(newstudent);
		tieude=0;
	}  
	}
	void chensx(Student *head) {
	    Student newstudent = malloc(sizeof(struct Node));
	    if (newstudent == NULL) {
	        printf("Khong du bo nho !\n");
	        return;
	    }
	  printf("Nhap ID :"); 
	  int tmp;
	  do{
	  	scanf("%d",&tmp);
	  	if (ID[tmp]==1) printf("ID bi trung !\nNhap lai :");
	  }
	  while(ID[tmp]==1);
	  ID[tmp]=1;
	  newstudent->student.ID=tmp;
	   printf("Nhap ho va ten : ");
	    getchar();
	    fgets(newstudent->student.name, sizeof(newstudent->student.name), stdin);
	  newstudent->student.name[strcspn(newstudent->student.name, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	  chuanhoaten(newstudent->student.name);
	    printf("Nhap ngay thang nam sinh (VD :19 4 2005) :");
	    scanf("%d %d %d",&newstudent->birth.day,&newstudent->birth.month,&newstudent->birth.year);
		 printf("Gioi Tinh : 1 - Nam   0 - Nu\nChon:");
		int tmp1;
		do{
	     scanf("%d",&tmp1);
	     if (tmp1==1) strcpy(newstudent->student.gioitinh,"Nam");
	     else if (tmp1==0) strcpy(newstudent->student.gioitinh,"Nu");
	     else printf("Chon lai gioi tinh :");
	 }
	 while(tmp1!=1&&tmp1!=0);
	 printf("Khoa : 1.CNTT(Cong nghe thong tin )\t2.Tu dong hoa(TDH)\t3.Co dien tu(CDT)\t4.Dien tu vien thong(DTVT)\n");
	 int tmp2;
	 do{
	     scanf("%d",&tmp2);
	     if (tmp2==1) strcpy(newstudent->student.khoa,"CNTT");
	     else if (tmp2==2) strcpy(newstudent->student.khoa,"TDH");
	     else if (tmp2==3) strcpy(newstudent->student.khoa,"CDT");
	     else if (tmp2==4) strcpy(newstudent->student.khoa,"DTVT");
	     else printf("Chon lai khoa(1-2-3-4) :");
	 }
	 while(tmp2!=1&&tmp2!=2&&tmp2!=3&&tmp2!=4);
	 int tmp3;
	char result[20];
	 int nienkhoa;
	 printf("Nien Khoa :"); 
	scanf("%d",&nienkhoa);
	      printf("Khoa %s - lop : 1.%d%s1\t2.%d%s2\t\t3.%d%s3\n",newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa,nienkhoa,newstudent->student.khoa);
	      do{
	     scanf("%d",&tmp3);
	if (tmp3==1) {sprintf(result, "%d%s1",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==2) {sprintf(result, "%d%s2",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	else if (tmp3==3) {sprintf(result, "%d%s3",nienkhoa,newstudent->student.khoa);
		 strcpy(newstudent->student.lop,result);
	}
	  else printf("Chon lai khoa(1-2-3) :");
	 }
	 while(tmp3!=1&&tmp3!=2&&tmp3!=3);
	       printf("Dia chi :");
	        getchar();
	        fgets(newstudent->student.diachi, sizeof(newstudent->student.diachi),stdin);
	         newstudent->student.diachi[strcspn(newstudent->student.diachi, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
	         chuanhoaten(newstudent->student.diachi);
	        printf("Email (VD: huan->huan@gmail.com) :");
	        char tmp4[20];
	        scanf("%s",tmp4);
	        strcat(tmp4,"@gmail.com");
	        strcpy(newstudent->student.email,tmp4);
	        printf("----->%s\n",tmp4);
	         nhapdiem(&newstudent->diem.toan,"Toan");
	  nhapdiem(&newstudent->diem.ly,"Ly");
	     nhapdiem(&newstudent->diem.tin,"Tin");
	       //bo sung cau lenh xuat ra sinh vien ban vua them vao danh sach
	    if (*head==NULL) {
	    	*head=newstudent;
	    	newstudent->next=newstudent;
	    	newstudent->prev=newstudent;
	    	insv(newstudent,1);
		}
		else {
		Student last=(*head)->prev;
		newstudent->next=*head;
		newstudent->prev=last;
		last->next=newstudent;
		(*head)->prev=newstudent;
		insv(newstudent,1);
		}
		free(newstudent);
	tieude=0;
	    printf("%77s","Them sinh vien thanh cong !\n");
	}  
	
	void deletesv08(Student *head,char nienkhoa[3]){
		if (*head==NULL){
			printf("Vui long bo sung du lieu sinh vien \n");
			return;
		}
		Student current=*head;
		int find=0;
		do{
		if (strncmp(current->student.lop,nienkhoa,2)==0 &&strcmp(current->student.gioitinh,"Nu")==0) {//neu node dau tien trong danh sach la sinh vien khoa 08
	        (*head) = current->next;
	        (*head)->prev = current->prev;
	        current->prev->next=*head;
	        current=current->next;
	    }
	}while(strncmp(current->student.lop,nienkhoa,2)==0&&strcmp(current->student.gioitinh,"Nu")==0);
		do{
			if (strncmp(current->student.lop,nienkhoa,2)==0&&strcmp(current->student.gioitinh,"Nu")==0){//neu no cung nien khoa 08 thi xoa
			find=1;
		if (current->next!=*head){
			current->prev->next=current->next;
			current->next->prev=current->prev;
		}
		else {
			current->prev->next=*head;
			(*head)->prev=current->prev;
		}
			}
			current=current->next;
		} while(current!=*head);
		if (!find) printf("Khong tim thay sinh vien co nien khoa %s\n",nienkhoa);
	}
		//cac option chinh	
		void option2(Student *head){//them sinh vien
			add(head);
		}
	    
	    void option1(Student head){//in ra danh sach sinh vien
	    display(head);
		}
		void option3(Student head){//tim kiem sinh vien
	    search(head);
		}
		
		void option5(Student *head){//chinh sua thong tin sinh vien
		printf("\x1b[38;2;0;255;255mNhap ID sinh vien muon chinh sua :\x1b[38;2;255;255;255m");
		scanf("%d",&EDS);
		editstudent(head,EDS);
		}
		
		void  option4(Student *head){//xoa sinh vien khoi danh sach
		printf("\x1b[38;2;0;255;255mNhap ID sinh vien muon xoa :\x1b[38;2;255;255;255m");
	    scanf("%d",&DID);
	    deleteNode(head,DID);
		}
	void option6(Student *head){
		int option ;
		printf("SAP XEP :\n");
		printf("1. Thu tu chu cai ten cua sinh vien \n");
		printf("2. Sinh vien theo tuoi\n");
		printf("3. Diem tu cao den thap \n");
		printf("4. Nien khoa tang dan\n");
		printf("5. ID\n");
		printf("6. Lop \n");
		printf("0.Ket thuc viec sap xep .\n");
		do{
			printf("\x1b[38;2;255;215;255mNhap lua chon sap xep :\x1b[38;2;255;255;255m"); scanf("%d",&option);
		switch(option){
			case 1: 
			arrangename(head);
			display(*head);
			printf("                     \x1b[38;2;255;215;255m-------------------Sap xep sinh vien theo ten thanh cong--------------\x1b[38;2;255;255;255m\n");
			return;
			case 2:
			arrangeage(head);
			display(*head);
			printf("                     \x1b[38;2;255;215;255m-------------------Sap xep sinh vien theo tuoi thanh cong--------------\x1b[38;2;255;255;255m\n");
			return;
			case 3 :
			sxdiem(head);
			printf("                     \x1b[38;2;255;215;255m-------------------Sap xep sinh vien theo diem thanh cong --------------\x1b[38;2;255;255;255m\n");
			return;
			case 4: 
			sxnienkhoa(head);
			display(*head);
			printf("                     \x1b[38;2;255;215;255m-------------------Sap xep thanh theo nien khoa thanh cong  --------------------\x1b[38;2;255;255;255m\n");
			return;
			case 5:
			arrangeID(head);
			display(*head);
			printf("                     \x1b[38;2;255;215;255m-------------------Sap xep thanh theo nien ID thanh cong  --------------------\x1b[38;2;255;255;255m\n");
			return;
			case 6:
				arrangeclass(head);
				display(*head);
			printf("                     \x1b[38;2;255;215;255m-------------------Sap xep thanh theo nien ID thanh cong  --------------------\x1b[38;2;255;255;255m\n");
			return;
			case 0: printf("                              \x1b[38;2;255;215;255m -----------------Ket thuc viec sap xep-------------------\x1b[38;2;255;255;255m \n");
			return;
			default:
				printf("Lua chon khong hop le !\n");
		}
	}
	while(option!=0);
	}
	void option7(Student *head){
		int tmp;
		do{
		printf("Chen sinh vien vao vi tri (>=0):");scanf("%d",&tmp);
		if (tmp<0) printf("Vi tri khong hop le !\n ");
	}
	while(tmp<0);
		chenbatki(head,tmp);
		tieude=0;
	}
	
	void option9(Student head){
		int option;
		printf("1 | Thong ke theo lop .\n");
		printf("2 | Thong ke theo khoa .\n");
		printf("Lua chon : ");
		do{
			scanf("%d",&option);
			if (option!=1&&option!=2){
				printf("Lua chon lai : ");
			}
		}
		while(option!=1&&option!=2);
		if (option==1){
		printf("                                            \x1b[38;2;255;215;0m------------------THONG KE--------------------\x1b[38;2;255;255;255m\n");
		arrangeclass(&head);
	    for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	    printf("|  \x1b[38;2;255;215;0m%-10s\x1b[38;2;255;255;255m  |  \x1b[38;2;255;0;255m%-15s\x1b[38;2;255;255;255m|  \x1b[38;2;124;252;0m%-30s\x1b[38;2;255;255;255m|  %-30s|     \x1b[38;2;0;255;255m%-15s\x1b[38;2;255;255;255m           |\n", "Lop", "So sinh vien","So sinh vien hoc bong 200","So sinh vien hoc bong 100","Tong hoc bong");
	    for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	    Student current = head;
	    do {
	        Student tmp = current;
	        int tonghb = 0;
	        int tongsv = 0;
	        int tongsv100 = 0;
	        int tongsv200 = 0;
	        do {
	            tongsv++;
	            if(tmp->diem.hocbong != 0) {
	                tonghb += tmp->diem.hocbong;
	                if (tmp->diem.hocbong == 200) tongsv200++;
	                else tongsv100++;
	            }
	            tmp = tmp->next;
	        } while(tmp != head && strcmp(current->student.lop, tmp->student.lop) == 0);
	        printf("|  \x1b[38;2;255;215;0m%-10s\x1b[38;2;255;255;255m  |       \x1b[38;2;255;0;255m%-5d\x1b[38;2;255;255;255m     |            \x1b[38;2;124;252;0m%-12d\x1b[38;2;255;255;255m        |             %-12d       |           \x1b[38;2;0;255;255m%-13d\x1b[38;2;255;255;255m       |\n", current->student.lop, tongsv, tongsv200, tongsv100, tonghb);
	        for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	        current = tmp;
	    } while(current != head);
	}
	else{
		printf("                                            \x1b[38;2;255;215;0m------------------THONG KE--------------------\x1b[38;2;255;255;255m\n");
		arrangekhoa(&head);
	    for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	    printf("|  \x1b[38;2;255;215;0m%-10s\x1b[38;2;255;255;255m  |  \x1b[38;2;255;0;255m%-15s\x1b[38;2;255;255;255m|  \x1b[38;2;124;252;0m%-30s\x1b[38;2;255;255;255m|  %-30s|     \x1b[38;2;0;255;255m%-15s\x1b[38;2;255;255;255m           |\n", "Lop", "So sinh vien","So sinh vien hoc bong 200","So sinh vien hoc bong 100","Tong hoc bong");
	    for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	    Student current = head;
	    do {
	        Student tmp = current;
	        int tonghb = 0;
	        int tongsv = 0;
	        int tongsv100 = 0;
	        int tongsv200 = 0;
	        do {
	            tongsv++;
	            if(tmp->diem.hocbong != 0) {
	                tonghb += tmp->diem.hocbong;
	                if (tmp->diem.hocbong == 200) tongsv200++;
	                else tongsv100++;
	            }
	            tmp = tmp->next;
	        } while(tmp != head && strcmp(current->student.khoa, tmp->student.khoa) == 0);
	        printf("|  \x1b[38;2;255;215;0m%-10s\x1b[38;2;255;255;255m  |       \x1b[38;2;255;0;255m%-5d\x1b[38;2;255;255;255m     |            \x1b[38;2;124;252;0m%-12d\x1b[38;2;255;255;255m        |             %-12d       |           \x1b[38;2;0;255;255m%-13d\x1b[38;2;255;255;255m       |\n", current->student.khoa, tongsv, tongsv200, tongsv100, tonghb);
	        for (int i=0 ; i<132; i++) printf("-");
	    printf("\n");
	        current = tmp;
	    } while(current != head);
	}
	}
	
	
	void option8(Student *head){
		chensx(head);
		arrangename(head);
		tieude=0;
	}
	
	void option10(Student head){
		deletesv08(&head,"08");
		display(head);
	}
		int main (){
		title();
	    Student head = malloc(sizeof(struct Node));
	    head=NULL;
	    Student thongke=malloc(sizeof(struct Node));
	    thongke=NULL;
	    docfile("qlsvtmp.txt",&head);
	    //docfile("qlsvloi.txt",&head);
	    menu();
	    char inmenu;
	    do {
	    	printf("\x1b[38;2;255;215;0mChon chuc nang Menu:\x1b[38;2;255;255;255m ");
	        scanf("%d", &choice);
	        switch (choice) {
	            case 1://in
	            display(head);
	            while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	            printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
	            break;
	            case 2: //them sinh vien
	             option2(&head);
	             ghifile(head,"qlsvtam.txt");
	             while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	            printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
	             break;
	           case 3://tim kiem sinh vien
	           if(head==NULL) {
	           	printf("Du lieu sinh vien khong ton tai . Vui long bo sung du lieu sinh vien !\n");
	           	break;
			   }
	           option3(head);
	           while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	             printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 4://xoa
			   if(head==NULL) {
	           	printf("Du lieu sinh vien khong ton tai . Vui long bo sung du lieu sinh vien !\n");
	           	break;
			   }
	           option4(&head);
	           ghifile(head,"qlsvtam.txt");
	           while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	           printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 5://chinh sua thong tin
			   if(head==NULL) {
	           	printf("Du lieu sinh vien khong ton tai . Vui long bo sung du lieu sinh vien !\n");
	           	break;
			   }
	           option5(&head);
	           ghifile(head,"qlsvtam.txt");
	           while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	           printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m ");    
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 6://sap xep
			   if(head==NULL) {
	           	printf("Du lieu sinh vien khong ton tai . Vui long bo sung du lieu sinh vien !\n");
	           	break;
			   }
	           option6(&head);
	           ghifile(head,"qlsvtam.txt");
	           while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	            printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m ");  
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 7://chen tai vi tri bat ki
			   option7(&head); 
			   ghifile(head,"qlsvtam.txt");
			   while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	           printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 8://chen nhung khong thay doi vi tri 
			   option8(&head);
			   ghifile(head,"qlsvtam.txt");
			   while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	          printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 9://thong ke
			   if(head==NULL) {
	           	printf("Du lieu sinh vien khong ton tai . Vui long bo sung du lieu sinh vien !\n");
	           	break;
			   }
			   option9(head);
			   while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	           printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 10://xoa cac ban nu khoa 08
			   if(head==NULL) {
	           	printf("Du lieu sinh vien khong ton tai . Vui long bo sung du lieu sinh vien !\n");
	           	break;
			   }
			   option10(head);
			   ghifile(head,"qlsvtam.txt");
			   while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
	          printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   case 11://doc file
			   head=NULL;
			   printf("Nhap ten file : ");
			   scanf("%s",tenfile);
			   docfile(tenfile,&head);
			   while(getchar() != '\n');//xoa bo \n truoc khi nhap ki tu
			   printf("\x1b[38;2;255;215;255m-----> Nhap m de in ra menu - Nhan bat ki de tiep tuc ! :\x1b[38;2;255;255;255m "); 
				scanf("%c",&inmenu);
	            if (inmenu=='m') {
	            	system("cls");
				menu();
			}
			   break;
			   default:
			   	printf(" Chuc nang ban chon khong hop le ! \n ");
		}
		} while (choice != 0);
	}