// Online C++ compiler to run C++ program online
#include <iostream>
#include <iomanip>
using namespace std;

struct QuestionNode{
    int q_no;
    char questions[100];
    char options[4][30];
    char correct_option;
    struct QuestionNode *next;
}*ptr1,*start1=NULL;

struct ResponseNode{
    int q_no;
    char correct_option;
    char user_option;
    int points_earned;
    struct ResponseNode *next;
}*ptr2,*start2=NULL;

void insertQuestion()
{
    ptr1=new QuestionNode;

    cout<<"Enter Question number: ";
    cin>>ptr1->q_no;
    cin.ignore();

    cout<<"Enter Question : ";
    cin.getline(ptr1->questions,100);

    cout<<"Enter option A: ";
    cin.getline(ptr1->options[0],30);

    cout<<"Enter option B: ";
    cin.getline(ptr1->options[1],30);

    cout<<"Enter option C: ";
    cin.getline(ptr1->options[2],30);

    cout<<"Enter option D: ";
    cin.getline(ptr1->options[3],30);

    cout<<"Enter Correct option: ";
    cin>>ptr1->correct_option;

    ptr1->correct_option=toupper(ptr1->correct_option);
    ptr1->next=NULL;

    if(start1==NULL)
    {
        start1=ptr1;
    }
    else
    {
        QuestionNode *temp1=start1;

        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }

        temp1->next=ptr1;
    }
}

void takequiz()
{
    QuestionNode *temp1=start1;

    int points_earned,current_score=0;

    while(temp1!=NULL)
    {
        cout<<"\nQuestion No: "<<temp1->q_no<<endl;
        cout<<temp1->questions<<endl;

        cout<<"A. "<<temp1->options[0]<<endl;
        cout<<"B. "<<temp1->options[1]<<endl;
        cout<<"C. "<<temp1->options[2]<<endl;
        cout<<"D. "<<temp1->options[3]<<endl;

        cout<<"Enter your answer: ";

        char answer;
        cin>>answer;

        answer=toupper(answer);

        ptr2=new ResponseNode;

        ptr2->q_no=temp1->q_no;
        ptr2->correct_option=temp1->correct_option;
        ptr2->user_option=answer;
        ptr2->next=NULL;

        if(answer==temp1->correct_option)
        {
            cout<<"STATUS: CORRECT"<<endl;
            points_earned=1;
            current_score++;
        }
        else
        {
            cout<<"STATUS: INCORRECT"<<endl;
            points_earned=0;
        }

        ptr2->points_earned=points_earned;

        if(start2==NULL)
        {
            start2=ptr2;
        }
        else
        {
            ResponseNode *temp2=start2;

            while(temp2->next!=NULL)
            {
                temp2=temp2->next;
            }

            temp2->next=ptr2;
        }

        temp1=temp1->next;
    }

    cout<<"\n\n==========================================================================";
    cout<<"\n                         FINAL PERFORMANCE REPORT";
    cout<<"\n==========================================================================\n";

    cout<<left
        <<setw(10)<<"Q.No."
        <<setw(10)<<"Correct"
        <<setw(12)<<"Your Ans"
        <<setw(15)<<"Status"
        <<setw(8)<<"Points"<<endl;

    cout<<"--------------------------------------------------------------------------"<<endl;

    ResponseNode *temp2=start2;

    while(temp2!=NULL)
    {
        cout<<left
            <<setw(10)<<temp2->q_no
            <<setw(10)<<temp2->correct_option
            <<setw(12)<<temp2->user_option;

        if(temp2->points_earned==1)
            cout<<setw(15)<<"CORRECT";
        else
            cout<<setw(15)<<"WRONG";

        cout<<setw(8)<<temp2->points_earned<<endl;

        temp2=temp2->next;
    }

    cout<<"--------------------------------------------------------------------------";
    cout<<"\nTOTAL SCORE : "<<current_score;
    cout<<"\n==========================================================================";
}
int main()
{
    int n;

    cout<<"Enter number of questions: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        insertQuestion();
    }

    takequiz();

    return 0;
}