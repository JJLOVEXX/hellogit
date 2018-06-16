#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


struct stu
{
   string name;
   string gender;
   double score;
};

bool cmp1(const stu &a, const stu &b)
{
    return a.score > b.score;   
}
bool cmp2(const stu &a,const stu &b)
{
     return a.name<b.name;
}

int main()
{
    ifstream ifs("score.csv");
    string name,gender;
    double score=0;
    double total=0;
    double maleScore=0;
    int maleCount=0;
    double femaleScore=0;
    int femaleCount=0;
    int count=0;

    vector<stu>student;

    while(ifs)
    {
        ifs>>name>>gender>>score;
        stu s;
        name.erase(std::remove(name.begin(),name.end(),','),name.end());
        gender.erase(std::remove(name.begin(),gender.end(),','),gender.end());
       
        s.name=name;
        s.gender=gender;
        s.score=score;

        student.push_back(s);

        total+=score;
        count++;
        if(gender.length()!=6)
        {
           maleScore+=score;
           maleCount++;
        }
        else
        {
           femaleScore+=score;
           femaleCount++;
        }
    }
    
    sort(student.begin(),student.end(),cmp1);
    sort(student.begin(),student.end(),cmp2);

    for(int k=0;k<count;k++)
    {
       cout<<student[k].name<<" "<<student[k].gender<<" "<<student[k].score<<endl;
    }

    cout<<setprecision(3)<<fixed;
    cout<<total/count<<endl;
    cout<<maleScore/maleCount<<endl;
    cout<<femaleScore/femaleCount<<endl;
    return 0;
}
