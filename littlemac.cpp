# include <iostream> 

int main () {

int eweight = 0;
int iweight = 0;
double gravity = 9.81;
int planet = 0;
std::string name = "  ";
std::string confirm = "  ";

std::cout<<"Hello fighter, please introduce your name:\n";
std::cin>>name;
std::cout<<"Nice to meet you, "<< name << "\n"<<"Please introduce your weight in kg :";
std::cin>>eweight;
std::cout<<"Your weight is "<< eweight <<" you want to confirm it?"<<"\n(type yes or no) ";
std::cin >> confirm;

while (confirm != "yes"){
    
    std::cout<< "Try again, type your weight in kg\n"; 
    std::cin >> eweight;
    std::cout<<"You want to confirm?\n";
    std::cin>> confirm;
    std::cout<<"Your weight is "<< eweight;
}

if (confirm == "yes") {

    std::cout<< "Let's calculate your interplanetary weight, in which planet you will fight?\n";
    std::cout<<"Mars = 1\nJupyter = 2\nMercury =3\n";
    std::cin>>planet;
    switch (planet){

        case 1:
        iweight = (eweight/9.91) * 8.2;
        std::cout<<"Your planetary weight is "<< iweight;
        break;

        case 2:
        iweight = (eweight/9.91) * 6.3;
        std::cout<<"Your planetary weight is "<< iweight;
        break;

        case 3:
        iweight = (eweight/9.91) * 8.2;
        std::cout<<"Your planetary weight is "<< iweight;
        break;
    }
}
}
