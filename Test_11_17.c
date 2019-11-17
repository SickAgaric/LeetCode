#include<iostream>
#include<string>


using namespace std;

int main()
{
    
    
    /*int _score = 0;
    
    if(str.size() < 5)
        _score = 5;
    else if(str.size() >= 5&&str.size() <=7)
        _score = 10;
    else
        _score = 25;
    
    int majuscule = 0,minuscule = 0;
    
    auto it = str.begin();
    
    while(it != str.end())
    {
        if(*it >= 'a' && *it <='z')
            minuscule++;
        if(*it >= 'A' && *it <= 'Z')
            majuscule++;
        it++;
    }
    
    if(minuscule > 0 && majuscule>0)
        _score += 20;
    else if(minuscule == 0 && majuscule > 0 || minuscule > 0 && majuscule == 0)
        _score += 10;
    else
        _score += 0;
    
    int number = 0;
    
    auto it = str.begin();
    
    while(it != str.end())
    {
        if(*it >= '0' && *it <= '9')
            number++;
        it++;
    }
    
    if(number > 1)
        _score += 20;
    else if(number == 1)
        _score += 10;
    else
        _score += 0;
    
    
    
    
    return 0;*/
    
    string str;
    cin >> str;
    
    int score = 0;
    int minuscule = 0,majuscule = 0;
    int number = 0;
    int symbol = 0;
    
    auto it = str.begin();
    
    while(it != str.end())
    {
        if(*it >= 'a' && *it <= 'z')
            minuscule++;
        else if(*it >= 'A' && *it <= 'Z')
            majuscule++;
        else if(*it >= '0' && *it <= '9')
            number++;
        else
            symbol++;
        it++;
    }
    
    if(str.size() <= 4)
        score += 5;
    else if(str.size() > 4 && str.size() <8)
        score += 10;
    else
        score += 25;
    
    if(minuscule == 0 && majuscule == 0)
        score += 0;
    else if(minuscule > 0 && majuscule == 0 || minuscule == 0 && majuscule > 0)
        score += 10;
    else
        score +=20;
    
    if(number == 0)
        score += 0;
    else if(number == 1)
        score += 10;
    else
        score += 20;
    
    if(symbol == 0)
        score += 0;
    else if(symbol == 1)
        score += 10;
    else
        score += 25;
        
    if((majuscule+minuscule)>0 && number>0 && symbol < 1)
        score +=2;
    else if((majuscule+minuscule)>0 && number>0 && symbol > 0)
        score +=3;
    else if(majuscule>0 && minuscule>0 && number>0 && symbol > 0)
        score +=5;
    
    
    if(score >= 90)
        cout << "VERY_SECURE";
    else if(score >= 80)
        cout << "SECURE";
    else if(score >= 70)
        cout << "VERY_STRONG";
    else if(score >= 60)
        cout << "STRONG";
    else if(score >= 50)
        cout << "AVERAGE";
    else if(score >= 25)
        cout << "WEAK";
    else
        cout << "VERY_WEAK";
    
    
    return 0;
        
        
        
}