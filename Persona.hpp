#include "Libreria.hpp"
class Persona
{
private:
   int id, age, experience, income, family,education, mortgage, ploan, securities,cd, online, creditcard;
   long zip;
   float  ccavrg;
   
public:
    Persona(int id=0,int age=0, int experience=0, int income=0, long zip=0, int family=0, float ccavrg=0.00,
            int education=0, int mortgage=0,int ploan=0,int securities=0, int cd=0,
            int online=0, int creditcard=0 ):id(id), age(age), experience(experience),income(income),
            zip(zip),family(family), ccavrg(ccavrg), education(education),mortgage(mortgage), ploan(ploan), 
            securities(securities),cd(cd), online(online), creditcard(creditcard){

            }
    ~Persona() {}


    friend ostream& operator << (ostream& s, const Persona& p){
        s<<p.id<<" "<<p.age<<" "<<p.experience<<" "<<p.income<<" "<<p.zip<<" "<<p.family<<" "<<p.education<<" "<<p.mortgage<<" "<<p.ploan<<" "<<p.securities<<" "<<p.cd<<" "<<p.online<<" "<<p.creditcard;
        return s;
    }

    int GetID(){return id;}
    int GetAge(){return age;}
    int GetExperience(){return experience;}
    int GetIncome(){return income;}
    long GetZip(){return zip;}
    int GetFamily(){return family;}
    float GetCcavrg(){return ccavrg;}
    int GetEducation(){return education;}
    int GetMortgage(){return mortgage;}
    int GetPloan(){return ploan;}
    int GetSecurities(){return securities;}
    int GetCD(){return cd;}
    int GetOnline(){return online;}
    int GetCreditcard(){return creditcard;}

    int SetFamily(int family){return this->family=family;}
  
};
