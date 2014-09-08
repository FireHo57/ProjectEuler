/**
*@brief this contains a number of functions designed ot find primes
**/

#pragma once

#include <cmath>
#include <vector>

struct primeMember
{
	int value;
	bool isPrime;

	primeMember( int i ): value( i ) , isPrime( true ){}
}

/**
*@brief this function takes a threshold then performs a search for all primes below that threshold. It returns a list of the primes
**/
std::vector<int> findPrimes( int threshold )
{
	//create the results list
	std::vector<int> resultsList;

	//work out roughly how many primes lie below the threshold using  primes(n) ~= n/naturalLog(n)
	float numberOfPrimes = threshold/log( threshold );
	
	//will need to round this and convert it to a size
	size_t numberOfPrimesSize = round( numberOfPrimes );
	
	//now we can create our results list properly :)
	//numberOfPrimeSize is just rough so we *may* need to make some more space later
	resultsList.reserve( numberOfPrimeSize );
	resultsList[0] = 2;
	resultsList[1] = 3;
	resultsList[2] = 5;
	
	//create the search list
	typedef std::vector< primeMember * > searchList;

	//
	searchList mySearchList(threshold);

	for( size_t i = 0 ; i < size_t( threshold ) ; ++i )
	{
		searchList[i] = primeMember( i );
	}
	
	//create an interator pointing at the next empty space in the results list	
	searchList::iterator emptyIter = results.begin();
	++emptyIter;
	++emptyIter;
	++emptyIter;
	for_each( searchList.begin() , searchList.end() , [&]( primeMember * p )
	{
		
	} );

	
	
}

