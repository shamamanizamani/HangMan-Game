#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int tries = 3;
string messege="You have 3 chances ";


void hang_man(char);
int checkguess(char,string,string&);

int main()
{

	char letter;
	string month;
	string months[12]={"january","feburary","march","april","may","june", "july","august","september","october","november","december"};

	srand(time(0));
	int month_number=rand()%12;
    month=months[month_number];

	string hide_month(month.length(),'X');

	system("cls");

	while(tries!=0)
	{
		hang_man('n');
		cout<< "\t\t\t\tLife: "<< tries<< endl;
		cout<< hide_month <<endl;
		cout<<"\t\t\t\tGuess a Letter: ";
		cin>>letter;

		system("cls");

		if(checkguess(letter ,month,hide_month) == 0)
		{
		messege="Incorrect letter!";
		tries--;
		}
		else{
			messege="Nice!Correct guess";
		}
		if(hide_month == month){
			messege="You are free!";
			hang_man('f');
				cout<< "\t\t\t\tLife: " << tries<< endl;
				cout<<"\t\t\t\tThe month is: "<<month<<endl;
				break;

		}

	}
	if(tries == 0){
    	messege=="You are Hanged! ";
		hang_man('h');
		cout<< "\t\t\t\tLife: " << tries<< endl;
			cout<<"\t\t\t\tThe month is: "<<month<<endl;

	}
	return 0;
}
int checkguess(char guess, string real_month ,string &hidden_month)
	{
		int matches = 0;
		int len= real_month.length();
		for (int i=0; i<len ;i++){
			if(guess == hidden_month[i]){
				return 0;
			}
			if(guess == real_month[i])
			{
				hidden_month[i] = guess;
				matches++;			}
//				return matches;
		}
		return matches;
	}

	void hang_man(char state){

		cout << "\t\t\t\t_________" << endl;
		cout << "\t\t\t\t          |         |" << endl;
		cout << "\t\t\t\t          O         | " << endl;
		cout << "\t\t\t\t         / \\       |"   <<"\t   " <<messege<<endl;
		cout << "\t\t\t\t          |         |" << "\t    /" <<endl;
		cout << "\t\t\t\t         /  \\      |            O  " << endl;
		if(tries!=0)
		{
		
		cout << "\t\t\t\t     ******|   /     / \\" << endl;
		cout << "\t\t\t\t       |      |     |  | |      |" << endl;
		cout << "\t\t\t\t       |      |     |  ***   / \\" << endl;
		cout << "\t\t\t\t****************" << endl;
	}
		else
		{
		
		cout<<"\t\t\t\t       *       *    | \\    / \\   "<<endl;
		cout << "\t\t\t\t       |      |     |   | |     |     " << endl;
		cout << "\t\t\t\t       |      |     |  ***   / \\" << endl;
		cout << "\t\t\t\t****************" << endl;
	}

	}
