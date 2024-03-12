#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> ids;
unordered_map<int,pair<string,string> > mp;
void join_gym(int n);
void getmdetails()
{
    ifstream getter("mdetails.txt");
    int id;
    string mem,dur;
    while(getter>>id>>mem>>dur)
    {
        pair<string,string> p1;
        p1.first=mem;
        p1.second=dur;
        mp[id]=p1;

    }

}
int slot1[5],slot2[5],slot3[5],slot4[5],slot5[5];
void getslots()
{
    ifstream trfile("trainers.txt");
    int ind=0;
    int s1,s2,s3,s4,s5;
    string t;
    while(trfile>>t>>s1>>s2>>s3>>s4>>s5)
    {
        if(ind<=4){
        slot1[ind]=s1;
        slot2[ind]=s2;
        slot3[ind]=s3;
        slot4[ind]=s4;
        slot5[ind]=s5;
        ind++;}
    }
    trfile.close();
}
void writeslots()
{

    ofstream temp("temp.txt",ios::app);
    for(int i=0;i<5;i++)
    {
        string stuff(i+1,'i');
        temp<<stuff<<" "<<slot1[i]<<" "<<slot2[i]<<" "<<slot3[i]<<" "<<slot4[i]<<" "<<slot5[i]<<"\n";
    }
    temp.close();
    remove("trainers.txt");
    rename("temp.txt","trainers.txt");
}
class BMI
{
    public:
    double h,w,a,bm;
    void gethw()
    {
        cout<<endl<<"------------BMI TRACKER------------"<<endl<<endl;
        cout<<"enter height in cm :";
        cin>>h;
        cout<<"enter your weight in kgs :";
        cin>>w;
        cout<<endl<<endl;
    }
    void bmi()
    {
        a=h/100;
        bm=w/(a*a);
        printf("Your bmi is : %.2f",bm);
        cout<<endl;
        if(bm<18.5)
        {
            cout<<"You're in under weight range "<<endl<<endl;
            cout<<"YOUR RECOMMENED DIET PLAN : "<<endl<<endl;
            cout<<"Underweight Diet Restrictions: Food Items To Limit"<<endl;
            cout<<"Whole Eggs."<<endl;
            cout<<"Leafy Greens."<<endl;
            cout<<"Salmon."<<endl;
            cout<<"Cruciferous Vegetables."<<endl;
            cout<<"Lean Beef and Chicken Breast."<<endl;
            cout<<"Boiled Potatoes."<<endl;
            cout<<"Tuna."<<endl;
            cout<<"Beans and Legumes."<<endl<<endl;
            cout<<"Do's And Dont's While Following Diet Plan for Underweight:\nIn Underweight condition, you can start making some simple changes in your lifestyles and food habits which are mentioned below\n";
            cout<<"Eat more oftenDrink Milk\nTry Weight gainer shakes\nUse Bigger Plates\nAdd cream to your coffee\nTake Creatine\nGet Quality Sleep\nEat your protein first and vegetables last\n";
            cout<<"Don'ts:\n";
            cout<<"Drink water before meals\nSmoke\n";
        }
        else if(bm>18.5 && bm<24.9)
        {
            cout<<"You're in healthy weight range "<<endl;
        }
        else if(bm>25 && bm<29.9)
        {
            cout<<"You're in over weight range "<<endl<<endl;
            cout<<"Best Tips From Diet Plan For Overweight People"<<endl;
            cout<<"Cut Down On Carbohydrates\nIncrease The Protein Intake\nKeep Fat To A Minimum\nEat Less Energy – Dense Foods\n";
            cout<<"Opt for foods that are high in fiber and water and low in calories.\nEat Frequently In Smaller Portions\n";
            cout<<"Reduce The Intake Of Salt\nEat Right Post – Workout\nUnderstand Your Daily Calorie Allowance\nEat Catechins To Stimulate Fat Burning\n";
            cout<<"Get Enough Calcium\n\n";
            cout<<"Recommended foods:\n";
            cout<<"1.Egg whites: There is no cholesterol or fat and they are pure protein. \nBesides, they are very easy to make, you just need a couple of minutes to make dishes with egg whites.\n";
            cout<<"2.Oatmeal: It is high in fiber, low in sugar and it provides energy. Opt for the old-fashioned variety in case you have several minutes to spare. \nIf you are in rush, you can use a packet of instant oatmeal. Just add boiling water,";
            cout<<"stir and enjoy.\n";
            cout<<"3. Green Veggies: Almost all of veggies are healthy and provide many health benefits. They contain any essential vitamins, antioxidants and phytochemicals for better health.\n";
            cout<<"Plus, they can fill you up for just several grams of carbs per serving of veggies.\n\n";

        }
        else
        {
            cout<<"You're in obese range"<<endl<<endl;
            cout<<"Do's And Dont's While following Diet Plan for Obesity"<<endl;
            cout<<"Try to avoid these food items if you are following obesity diet plan:"<<endl;
            cout<<"Rely on soft drinks, sweetened cereals, cookies and cakes, donuts and pastries, chips, and confectionery to get you through the day."<<endl;
            cout<<"Don't skip meals. This will tempt you to snack and DO NOT snack between meals"<<endl;
            cout<<"Avoid eating quickly. Sit and chew each bite. Try using chopsticks!"<<endl;
            cout<<"Don't food shop when you're hungry."<<endl;
            cout<<"Don't eat more than two or three pieces of fruit per day"<<endl<<endl;
            cout<<"Add these food items to your diet chart if you are following obesity diet plan :"<<endl;
            cout<<"Eat more vegetables - add them at every meal."<<endl;
            cout<<"Drink plenty of water - you can become hungry when thirsty."<<endl;
            cout<<"Try eating off smaller plates so as to eat smaller portions"<<endl;
            cout<<"Exercise between 30 minutes to one hour each day with moderate exercise - brisk walking, team sport, cycling or swimming."<<endl;
            cout<<"Be mindful of what you put in your mouth and your shopping trolley."<<endl;
        }
    }
};
class user : public BMI
{
    private:
    string name,phone,email,dob,add;
    int hei,wei;
    string un,pw;
    string mode;
    public:
    void getids()
    {
        string e,p,n,ph,db,h,w,ress;
        int id1;
        ifstream reader("users.txt");
        while(reader>>id1>>n>>ph>>db>>h>>w>>ress>>e>>p)
        {

            ids.push_back(id1);
        }


    }
    int createuser()
    {
    ofstream myfile("users.txt",ios::app);
    cout<<"\n\t\t\t\t\t---ENTER YOUR DETAILS---";
    cout<<"\nEnter Name:";
    cin>>name;
    cout<<"Enter Phone number:";
    cin>>phone;
    cout<<"Enter Date of birth : ";
    cin>>dob;
    cout<<"Enter Height : ";
    cin>>hei;
    cout<<"Enter Weight : ";
    cin>>wei;
    cout<<"Enter the Address : ";
    cin>>add;
    cout<<"Enter Email:";
    cin>>email;
    cout<<"Enter Password:";
    cin>>pw;

    ifstream fopen1("users.txt");
    srand(time(0));
    int idno=2044;
    while((count(ids.begin(),ids.end(),idno)))
    {
        idno=rand();

    }
    myfile<<idno<<"  "<<name<<"  "<<phone<<"  "<<dob<<"  "<<hei<<"  "<<wei<<"  "<<add<<"  "<<email<<"  "<<pw<<"\n";
    ofstream getfile("mdetails.txt",ios::app);
    getfile<<idno<<"  "<<"none"<<"  "<<"none\n";
    system("cls");
    cout<<"\n\nYOUR ID NUMBER IS:"<<idno<<endl;
    cout<<"PLEASE KEEP A NOTE OF YOUR ID NUMBER"<<endl;
    cout<<"ACCOUNT CREATED SUCCESSFULLY!!"<<endl;
    getfile.close();
    myfile.close();
    return idno;


    }
    void quitgym1(string em)
    {
        ifstream users("users.txt");
        ofstream ofs("temp.txt",ios::app);
        string idd,namee,phh,dobb,hh,ww,ad1,em1,pw1;
        while(users>>idd>>namee>>phh>>dobb>>hh>>ww>>ad1>>em1>>pw1)
        {
            if(em==em1)
                continue;
            else
                ofs<<idd<<"  "<<namee<<"  "<<phh<<"  "<<dobb<<"  "<<hh<<"  "<<"  "<<ww<<"  "<<ad1<<"  "<<em1<<"  "<<pw1<<"\n";
        }
        ofs.close();
        users.close();
        remove("users.txt");
        rename("temp.txt","users.txt");
        cout<<"YOU HAD QUIT THE GYM"<<endl;
    }
    void quitgym2(int id)
    {
        ifstream mfile("mdetails.txt");
        ofstream ofs("temp.txt",ios::app);
        string mem,dur;
        int idd;
        while(mfile>>idd>>mem>>dur)
        {
            if(id==idd)
                continue;
            else
                ofs<<idd<<"  "<<mem<<"  "<<dur<<"\n";
        }
        mfile.close();
        ofs.close();
        remove("mdetails.txt");
        rename("temp.txt","mdetails.txt");


    }
    void quitgym3(int id)
    {
        getslots();
        for(int i=0;i<6;i++)
        {
            if(slot1[i]==id)
                slot1[i]=0;
            if(slot2[i]==id)
                slot2[i]=0;
            if(slot3[i]==id)
                slot3[i]=0;
            if(slot4[i]==id)
                slot4[i]=0;
            if(slot5[i]==id)
                slot5[i]=0;
        }
        writeslots();
    }
    void editprofile(string emm)
    {
        ifstream users("users.txt");
        ofstream ofs("temp.txt",ios::app);

        string idd,namee,phh,dobb,hh,ww,ad1,em1,pw1;
        string target;
        while(users>>idd>>namee>>phh>>dobb>>hh>>ww>>ad1>>em1>>pw1)
        {

            if(emm==em1){
                target=idd;
                //display current details
                cout<<"-------------------YOUR CURRENT PROFILE DETAILS:-------------------"<<endl;
                cout<<"ID NUMBER:"<<idd<<endl;
                cout<<"NAME:"<<namee<<endl;
                cout<<"PHONE NUMBER:"<<phh<<endl;
                cout<<"DATE OF BIRTH:"<<dobb<<endl;
                cout<<"HEIGHT:"<<hh<<endl;
                cout<<"WEIGHT:"<<ww<<endl;
                cout<<"ADDRESS:"<<ad1<<endl;
                cout<<"E-MAIL:"<<em1<<endl;
                cout<<"PASSWORD:"<<pw1<<endl;
            }
            else
                ofs<<idd<<"  "<<namee<<"  "<<phh<<"  "<<dobb<<"  "<<hh<<"  "<<"  "<<ww<<"  "<<ad1<<"  "<<em1<<"  "<<pw1<<"\n";
        }
        cout<<"-------------------ENTER NEW PROFILE DETAILS BELOW:-------------------"<<endl;
        cout<<"enter name:";
        cin>>namee;
        cout<<"enter phone number:";
        cin>>phh;
        cout<<"enter Date of birth : ";
        cin>>dobb;
        cout<<"enter height : ";
        cin>>hh;
        cout<<"enter weight : ";
        cin>>ww;
        cout<<"enter the address : ";
        cin>>ad1;
        cout<<"enter email:";
        cin>>em1;
        cout<<"enter password:";
        cin>>pw1;
        ofs<<target<<"  "<<namee<<"  "<<phh<<"  "<<dobb<<"  "<<hh<<"  "<<"  "<<ww<<"  "<<ad1<<"  "<<em1<<"  "<<pw1<<"\n";

        ofs.close();
        users.close();
        remove("users.txt");
        rename("temp.txt","users.txt");
        cout<<"YOUR PROFILE HAS BEEN UPDATED.."<<endl;
    }
    void userlogin()
    {
        int cou=0;
        string ee,pp,e,p,n,ph,db,h,w,ress;
       int k;
       int id;
        cout<<"Press '1' to know more about our gym\nPress '2' to create a new account\nPress any other number to login\n";
        cin>>k;
        system("cls");
        if(k==1)
        {
            //display gym equipment details
            cout<<endl<<"We provide the following gym equipment:"<<endl;
            cout<<"Adjustable dumbbells\nDumbbells\nElliptical machine\nHome gyms\nRecumbent bike\n";
            cout<<"Resistance bands\nRowing machine\nSpin bike\nTreadmill\nUpright bike\nArm extension machine\n";
            cout<<"Leg press machine\nHack squat\nBench Press\n";

        }
        else if(k==2)
        {
           id=createuser();
           int choice;
           cout<<"\nLOGGED IN SUCCESSFULLY!!\n"<<endl;
           cout<<"1.Join gym\n2.QUIT\n\n";
           cout<<"enter your choice:";
           cin>>choice;
           switch(choice)
           {
               case 1:join_gym(id);
               break;

               default:exit(0);
               break;
           }



        }

        else
        {
        cout<<"enter email : ";
        cin>>ee;
        cout<<"enter password : ";
        cin>>pp;
        string line1;
        ifstream myfiler("users.txt");
        while(myfiler>>id>>n>>ph>>db>>h>>w>>ress>>e>>p)
        {

            if(ee==e && pp==p)
            {
                cou=1;
                break;
            }
        }
        myfiler.close();
        if(cou==1)
        {
            cout<<"\nLOGGED IN SUCCESSFULLY!!\n"<<endl;
            cout<<"1.Quit gym\n2.Edit Profile\n3.Bmi tracker\n";
            int choice;
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice)
            {
                    case 1: quitgym1(ee);
                            quitgym2(id);
                            quitgym3(id);
                            break;
                    case 2:editprofile(ee);
                             break;
                    case 3:gethw();
                    bmi();
                    break;

                    default:cout<<endl<<"invalid choice!!"<<endl;
                    break;




            }

        }
        else
        {

            cout<<"INVALID PASSWORD/E-MAIL"<<endl;
        }

    }

    }




};
class trainer:public user
{
public:
    void display_timetable(string trai)
    {
        ifstream fin("trainers.txt");
        int s1,s2,s3,s4,s5;
        string t;
        while(fin>>t>>s1>>s2>>s3>>s4>>s5)
        {
            if(t==trai)
            {
                cout<<endl<<endl<<"--------------your timetable is as below--------------"<<endl;
                if(s1==0)
                    cout<<"slot-1 : NULL"<<endl;
                else
                    cout<<"slot-1 : user-"<<s1<<endl;
                if(s2==0)
                    cout<<"slot-2 : NULL"<<endl;
                else
                    cout<<"slot-2 : user-"<<s2<<endl;
                if(s3==0)
                    cout<<"slot-3 : NULL"<<endl;
                else
                    cout<<"slot-3 : user-"<<s3<<endl;
                if(s4==0)
                    cout<<"slot-4 : NULL"<<endl;
                else
                    cout<<"slot-4 : user-"<<s4<<endl;
                if(s5==0)
                    cout<<"slot-5 : NULL"<<endl;
                else
                    cout<<"slot-5 : user-"<<s5<<endl;

            }
        }
    }
    void tlogin()
    {
        string un,pw;
        string f_un,f_pw;
        int res=0;
        ifstream topen("trainer-credentials.txt");
        cout<<endl<<endl;
        cout<<"enter user-name:";
        cin>>un;
        cout<<"enter password:";
        cin>>pw;
        while(topen>>f_un>>f_pw)
        {
            if(un==f_un && pw==f_pw)
            {
                res=1;
            }
        }
        if(res==1)
        {
            cout<<endl<<"YOU HAVE LOGGED IN SUUCCESSFULLY!!"<<endl;
            display_timetable(un);
        }
        else
        {
            cout<<endl<<"INVALID USER-NAME/PASSWORD"<<endl;
        }
    }
};
class admin : public user
{
private:
    string ad_pw="GymLogin_13";
public:
    string apw;
    int opt;
    void displayusers()
    {
        cout<<"THE DETAILS OF THE USERS ARE AS BELOW:"<<endl;

        string e,p,n,ph,db,h,w,ress;
        int id1;
        ifstream userslist("users.txt");
        while(userslist>>id1>>n>>ph>>db>>h>>w>>ress>>e>>p)
        {
            cout<<"ID NUMBER:"<<id1<<endl;
            cout<<"NAME:"<<n<<endl;
            cout<<"PHONE NUMBER:"<<ph<<endl;
            cout<<"DATE OF BIRTH:"<<db<<endl;
            cout<<"HEIGHT:"<<h<<endl;
            cout<<"WEIGHT:"<<w<<endl;
            cout<<"ADDRESS:"<<ress<<endl;
            cout<<"E-MAIL:"<<e<<endl;
            pair<string,string>det;
            for(auto x:mp)
            {
                if(x.first==id1)
                {
                    pair<string,string> p=x.second;
                    det.first=p.first;
                    det.second=p.second;
                }
            }

            cout<<"MEMBERSHIP DETAILS:"<<det.first<<" "<<det.second<<endl;
            cout<<"----------------------------------------"<<endl;
        }
        userslist.close();
    }
    void searchuser()
    {
        bool flag=false;
        cout<<"THE ID NUMBERS OF USERS ARE LISTED BELOW:"<<endl;
        for(int id:ids)
        {
        cout<<id<<endl;
        }
        int key;
        cout<<"Enter the id number of user you want to search:";
        cin>>key;


        string e,p,n,ph,db,h,w,ress;
        int id1;
        ifstream userslist("users.txt");
        while(userslist>>id1>>n>>ph>>db>>h>>w>>ress>>e>>p)
        {
            if(id1==key)
            {
                flag=true;
                cout<<"----------------------THE DETAILS OF THE USERS YOU SEARCHED FOR ARE AS BELOW:-----------------------\n";
                cout<<"ID NUMBER:"<<id1<<endl;
                cout<<"NAME:"<<n<<endl;
                cout<<"PHONE NUMBER:"<<ph<<endl;
                cout<<"DATE OF BIRTH:"<<db<<endl;
                cout<<"HEIGHT:"<<h<<endl;
                cout<<"WEIGHT:"<<w<<endl;
                cout<<"ADDRESS:"<<ress<<endl;
                cout<<"E-MAIL:"<<e<<endl;
                pair<string,string>det;
                for(auto x:mp)
                {
                if(x.first==key)
                {
                    pair<string,string> p=x.second;
                    det.first=p.first;
                    det.second=p.second;
                }
               }

                cout<<"MEMBERSHIP DETAILS:"<<det.first<<" "<<det.second<<endl;
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                break;
            }


        }
        userslist.close();
        if(flag==false)
        {
            cout<<"ENTERED ID NOT FOUND!!"<<endl;
        }

    }
    void trainer_allotment(int id,int slot)
    {
        int i;
            switch(slot)
            {
                case 1:for(i=0;i<5;i++){
                    if(slot1[i]==0)
                    {
                        slot1[i]=id;
                        cout<<"your trainer is trainer-"<<i+1<<endl;
                        break;
                    }
                    else
                    {
                        if(i==4)
                            cout<<"SELECTED SLOT NOT AVAILABLE.."<<endl;
                    }

                }
                break;

                case 2:for(i=0;i<5;i++){
                    if(slot2[i]==0)
                    {
                        slot2[i]=id;
                        cout<<"your trainer is trainer-"<<i+1<<endl;
                        break;
                    }
                    else
                    {
                        if(i==4)
                            cout<<"SELECTED SLOT NOT AVAILABLE.."<<endl;
                    }

                }
                break;

                case 3:for(i=0;i<5;i++){
                    if(slot3[i]==0)
                    {
                        slot3[i]=id;
                        cout<<"your trainer is trainer-"<<i+1<<endl;
                        break;
                    }
                    else
                    {
                        if(i==4)
                            cout<<"SELECTED SLOT NOT AVAILABLE.."<<endl;
                    }

                }
                break;

                case 4:for(i=0;i<5;i++){
                    if(slot4[i]==0)
                    {
                        slot4[i]=id;
                        cout<<"your trainer is trainer-"<<i+1<<endl;
                        break;
                    }
                    else
                    {
                        if(i==4)
                            cout<<"SELECTED SLOT NOT AVAILABLE.."<<endl;
                    }

                }
                break;

                case 5:for(i=0;i<5;i++){
                    if(slot5[i]==0)
                    {
                        slot5[i]=id;
                        cout<<"your trainer is trainer-"<<i+1<<endl;
                        break;

                    }
                    else
                    {
                        if(i==4)
                            cout<<"SELECTED SLOT NOT AVAILABLE.."<<endl;
                    }

                }
                break;
            }

    }
    void createmembership(int id)
    {
        //system("cls");

        ofstream getfile("mdetails.txt",ios::app);
        cout<<"Join gym"<<endl<<endl;

                        cout<<"\nThere are 2 Membership options as listed below : \n\n1.Silver : \ni.Trainer will not be provided\nii.Weekly 15hours  Gym accessibility\niii.SIX Months---RS.10,000/-\n";
                        cout<<"iv.ONE Year---RS.18,000/-\n"<<"\n2.Gold : \ni.Trainer will be provided\nii.Weekly unlimited hours Gym accessibility\niii.SIX Months---RS.20,000/-\n";
                        cout<<"iv.ONE Year---RS.38,000/-\n";
                        cout<<"\nEnter which Membership u want to purchase : ";
                        int sg;
                        cin>>sg;
                        if(sg==1)
                        {
                            cout<<"\nEnter the duration for which you want to purchase the membership(press 1 for six months 2 for one year) : ";
                            int ship;
                            cin>>ship;
                            if(ship==1)
                            {
                                cout<<"\nAmount to be paid is 10,000/-\n";
                                cout<<"Enter your UPI ID : ";
                                string upi;
                                cin>>upi;
                                int pin;
                                cout<<"Enter UPI pin : ";
                                cin>>pin;
                                cout<<"Your Payment is successfull\n";
                                //mp[id]="silver for 6 months";
                                getfile<<id<<"  "<<"silver"<<"  "<<"6-months\n";
                            }
                            else if(ship==2)
                            {
                                cout<<"\nAmount to be paid is 18,000/-\n";
                                cout<<"Enter your UPI ID : ";
                                string upi;
                                cin>>upi;
                                int pin;
                                cout<<"Enter UPI pin : ";
                                cin>>pin;
                                cout<<"Your Payment is successfull\n";
                                //mp[id]="silver for 1 year";
                                getfile<<id<<"  "<<"silver"<<"  "<<"1-year\n";
                            }
                            else
                            {
                                cout<<"Invalid choice!!"<<endl;
                            }

                        }
                        else if(sg==2)
                        {
                            cout<<"\nEnter the duration for which you want to purchase the membership(press 1 for six months 2 for one year) : ";
                            int ship;
                            cin>>ship;
                            if(ship==1)
                            {
                                cout<<"\nAmount to be paid is 20,000/-\n";
                                cout<<"Enter your UPI ID : ";
                                string upi;
                                cin>>upi;
                                int pin;
                                cout<<"Enter UPI pin : ";
                                cin>>pin;
                                cout<<"Your Payment is successful\n";
                                //mp[id]="gold for 6 months";
                                getfile<<id<<"  "<<"gold"<<"  "<<"6-months\n";
                                int slot_time;
                                cout<<"\n press 1 for: morning 6-7\n press 2 for: morning 7-8\n press 3 for: morning 8-9\n";
			cout<<" press 4 for: evening 4-5\n press 5 for: evening 5-6\n\n";
			cout<<"PLEASE SELECT YOUR PREFERRED TIMINGS:";
			cin>>slot_time;
                                getslots();
                                trainer_allotment(id,slot_time);
                                writeslots();

                            }
                            else if(ship==2)
                            {
                                cout<<"\nAmount to be paid is 38,000/-\n";
                                cout<<"Enter your UPI ID : ";
                                string upi;
                                cin>>upi;
                                int pin;
                                cout<<"Enter UPI pin : ";
                                cin>>pin;
                                cout<<"Your Payment is successful\n";
                                //mp[id]="gold for 1 year";
                                getfile<<id<<"  "<<"gold"<<"  "<<"1-year\n";
                                int slot_time;
                                cout<<"\n press 1 for: morning 6-7\n press 2 for: morning 7-8\n press 3 for: morning 8-9\n";
			cout<<" press 4 for: evening 4-5\n press 5 for: evening 5-6\n\n";
			cout<<"PLEASE SELECT YOUR PREFERRED TIMINGS:";
			cin>>slot_time;
                                getslots();
                                trainer_allotment(id,slot_time);
                                writeslots();
                            }
                            else
                            {
                                cout<<"Invalid choice!!"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"Invalid choice"<<endl;
                        }
                        getfile.close();
    }
    void editmembership(int key)
    {
        int id;
        string mem,dur;
        string a,b;
        ifstream dets("mdetails.txt");
        ofstream temp1("tempfile.txt",ios::app);
        cout<<"-------------------------EDITING THE MEMBERSHIP OF USER(ID:"<<key<<")-------------------------\n";
        while(dets>>id>>mem>>dur)
        {
            if(key==id)
                continue;
            else
                temp1<<id<<"  "<<mem<<"  "<<dur<<"\n";
        }
        cout<<"Enter the new membership(gold/silver):";
        cin>>a;
        cout<<"Enter the new duration(6-months/1-year):";
        cin>>b;
        temp1<<key<<"  "<<a<<"  "<<b<<"\n";
        cout<<"The membership of user(ID:"<<key<<") was changed to: "<<a<<" "<<b<<endl;
        dets.close();
        temp1.close();
        remove("mdetails.txt");
        rename("tempfile.txt","mdetails.txt");


    }
    void deletemembership(int key)
    {
        ifstream dets("mdetails.txt");
        ofstream temp1("tempfile.txt",ios::app);
        int id;
        string mem,dur;
        while(dets>>id>>mem>>dur)
        {
            if(key==id)
                continue;
            else
                temp1<<id<<"  "<<mem<<"  "<<dur<<"\n";
        }
        temp1<<key<<"  "<<"none"<<"  "<<"none\n";
        cout<<"The membership of user(ID:"<<key<<") was deleted."<<endl;
        dets.close();
        temp1.close();
        remove("mdetails.txt");
        rename("tempfile.txt","mdetails.txt");


    }
    void adminlogin()
    {
        cout<<"Enter the password to login as admin:";
        cin>>apw;
        if(ad_pw==apw)
        {
            cout<<"\nYOU HAVE LOGGED IN SUCCESSFULLY AS ADMIN!!"<<endl;
            cout<<"\n1.Create membership\n2.Display all users\n3.Search a user\n4.Edit Membership\n5.Delete Membership\n\n";
            cout<<"Enter your choice:";
            cin>>opt;
            switch(opt)
            {
                case 1://create membership
                       int iddd;
                       cout<<"Enter the id number of user to create his/her membership:";
                       cin>>iddd;
                       createmembership(iddd);
                       break;
                case 2://display users
                       cout<<"THE DETAILS OF THE USERS ARE AS BELOW:"<<endl;
                       displayusers();
                       break;
                case 3://search user
                       searchuser();
                       break;
                case 4://edit membership
                       cout<<"enter the user's id number to edit his/her membership:";
                       cin>>iddd;
                       editmembership(iddd);
                       break;
                case 5:cout<<"enter the user's id number to delete his/her membership:";
                       cin>>iddd;
                       deletemembership(iddd);
                       break;
                default:cout<<"Invalid choice!!\n";
                        break;

            }
        }
        else
        {
            cout<<"INCORRECT PASSWORD!!!"<<endl;
        }
    }


};
admin a1;
void join_gym(int n){
        a1.createmembership(n);}
int main()
{
     user uu;
     uu.getids();
     getmdetails();
     trainer t1;

     int mode;
     cout<<"\n\t\t\t\t---------------------";
     cout<<"\n\t\t\t\tGYM MANAGEMENT SYSTEM";
     cout<<"\n\t\t\t\t---------------------";
     cout<<"\n\t\t\t\t1.USER\n\t\t\t\t2.TRAINER\n\t\t\t\t3.ADMIN\n";
     cout<<"Enter mode to login:";
     cin>>mode;
     system("cls");
     switch(mode)
     {

         case 1:cout<<"\t\t\t\tINSTRUCTIONS FOR BEGINNERS:\n\n1.Create an account\n2.After creation of account keep a note of your alloted ID-number\n3.Login using your e-mail and password\n\nHERE YOU GO!!!\n\n";
                uu.userlogin();
                break;

         case 2:t1.tlogin();
                break;
         case 3:a1.adminlogin();
                break;
         default:cout<<"you entered an invalid mode!"<<endl;
                 break;
     }


}
