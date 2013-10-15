//NIM dabs október 1997
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

//Þetta fall á að birta stöðu allra eldspýtnahrúgna (hrúgur í fleirtölu eignarfalli)
void birta( int* hruga );

//Þetta fall á að reikna út hversu margar eldspýtur eru eftir í hrúgunum:
int samtals( int* hruga );

//Þetta fall lætur tölvuna gera:
void tolva( int* hruga );

//Þetta fall lætur notandann gera:
void notandi( int* hruga );

//Þetta fall birtir reglurnar í spilinu:
void hjalp( );

//Þetta fall spilar spilið:
void spila( );

//Ég leyfi mér að nota eina víðværa breytu af því að forritið notar alltaf
//mismargar hrúgur í hvert og eitt skipti:
int hrugufjoldi;

//Hér byrjar aðalforritið:
int main( )
{
	int val;
	do
	{
		cout << endl << endl << endl;
		cout << "                MAIN MENU " << endl << endl;
		cout << "                      1. Play  NIM" << endl;
		cout << "                      2. How to play NIM" << endl;
		cout << "                      3. Quit " << endl << endl;
                cout << "                      4. Authors of project " << endl << endl;
		cout << "                      Choose 1, 2, 3 eda 4:" << endl << endl;
		cin >> val;
		switch ( val )
		{
		case 1:
			spila( );
			break;
		case 2:
			hjalp( );
			break;
		case 3:
			break;
                case 4:
                        cout << "The authors of this project are  Karitas Olafsdottir and Johanna Dora Ingolfsdottir" << endl;
                        break;
		}
	}
	while ( val != 3 );

	return 0;
}

void spila( )
{
	int hruga[ 10 ];
	cout << "*-------------------------------------------------------*" << endl;
	cout << "                   NOW WE PLAY NIM!!" << endl;
	cout << "*-------------------------------------------------------*" << endl;
	cout << endl << endl;
	cout << "Choose how many piles we want to play. " << endl;
	cout << "Press any key: " << endl;

	srand( time( 0 ) );	

	hrugufjoldi = ( (rand( ) % 8 ) + 2 );
	cout << "We play with " << hrugufjoldi << " piles. " << endl;

	for ( int i = 0; i < hrugufjoldi; i++ )
	{
		hruga[ i ]=( ( rand( ) % 14 ) + 1 );
	}

	cout << endl;
	birta ( hruga );

	do
	{
		notandi( hruga );
		birta( hruga );
		tolva( hruga );
		birta( hruga );
	}
	while ( samtals( hruga ) );
}

void hjalp( )
{
	cout << "              AOUT THE NIM - GAME " << endl << endl;
	cout << "Nim is originally from Asia where it was " << endl;
	cout << "played with pebbles. The rules are: " << endl;
	cout << "Players put any amout of matches in piles " << endl;
	cout << "(they decide themselves how many piles and how many " << endl;
	cout << "matches are in a pile) and then take turns at " << endl;
	cout << "drawing matches from one of the piles. They can " << endl;
	cout << "take one match, a couple or all of them from one " << endl;
	cout << "pile, but they can never draw matches from more than " << endl;
	cout << "one pile at a time. The one who takes the last match " << endl;
	cout << "from the last pile wins. Good luck!" << endl << endl;
	cout << "Press any key... " << endl;
	getchar( );
}

void birta( int* hruga )
{
	if( !samtals( hruga ) )
	{
		return;
	}
	cout << "                         Pile number.: ";
	for (int i = 0; i < hrugufjoldi; i++ )
	{
		cout << " " << (i + 1) << "  ";
	}

	cout << endl << endl;
	cout << "The amont of matches in every pile is: ";
	for ( int c = 0; c < hrugufjoldi; c++ )
	{
		if( hruga[c] < 10 )
		{
			cout << " " << hruga[ c ] << "  ";
		}
		else
		{
			cout << hruga[ c ] << "  ";
		}
	}
	cout << endl << endl;
}

void notandi( int* hruga )
{
	if ( samtals( hruga ) == 0 )
	{
		return;
	}
	int eldspytur;
	int hrugunumer;
	do
	{
		cout << "How many matches do you want to take? ";
		cin >> eldspytur;
		cout << endl;
		if( eldspytur < 1 )
		{
			cout << "You must take at least one match. Try again. " << endl << endl;
			continue;
		}
		cout << "Say which pile you wish to draw from: ";
		cin  >> hrugunumer;
		if( hrugunumer > hrugufjoldi )
		{
			cout << "There is no pile with that number. Try again." <<endl<<endl;
			continue;
		}
		if( eldspytur > hruga[ (hrugunumer) - 1 ] )
		{
			cout <<"There are not enough matches left in the pile."<<endl<<endl;
			continue;
		}
	}
	while ( eldspytur > hruga[ (hrugunumer) - 1 ] || eldspytur < 1 );

	hruga[ hrugunumer - 1 ] -= eldspytur;
	if( !samtals( hruga ) )
	{
		cout << endl << "You won. Congratulations!" << endl << endl;
		cout <<  "Press any key... " << endl;
		getchar( );
	}
	cout << endl;
}

void tolva( int* hruga )
{
	if( samtals( hruga ) == 0 )
	{
		return;
	}

	int eldspytur;
	int hrugunumer;

	do
	{
		eldspytur = ( ( rand( ) % 14 ) + 1 );
		hrugunumer = ( ( rand( ) % hrugufjoldi ) + 1 );
		if( eldspytur > hruga[(hrugunumer)-1] )
		{
			continue;
		}
	}
	while ( eldspytur > hruga[ (hrugunumer) - 1 ] );

	if ( eldspytur > 1 )
	{
		cout << "      I draw " << eldspytur << " mathces from pile number ";
	}
	else 
	{
		cout << "      I draw " << eldspytur << " match from pile number ";
	}
	cout << hrugunumer << "." << endl;

	hruga[ (hrugunumer) - 1 ] -= eldspytur;
	if( !samtals( hruga ) )
	{
		cout << endl << "I won. Better luck next time!" << endl << endl;
		cout << " Press any key...   " << endl;
		getchar( );
	}
	cout << endl;
}

int samtals( int* hruga )
{
	int samtala = 0;
	for( int i = 0; i < hrugufjoldi; i++ )
	{
		samtala += hruga[ i ];
	}

	return samtala;
}
