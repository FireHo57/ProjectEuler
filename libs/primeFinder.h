/**
*@brief this contains a number of functions designed ot find primes
**/

#pragma once

#include <cmath>
#include <vector>

struct primeMember
{
	int _value;
	bool _isPrime;

	primeMember( int i ): _value( i ) , _isPrime( true ){}
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
	
	//create the search list
	typedef std::vector< primeMember * > searchList;

	//
	searchList mySearchList(threshold);

	for( size_t i = 0 ; i < size_t( threshold ) ; ++i )
	{
		searchList[i] = primeMember( i );
	}

	//the first members of the search list must be discounted (as they are 0 , 1 respectively)
	searchList[0]->_isPrime=false;
	searchList[1]->_isPrime=false;	

	//create an interator pointing at the next empty space in the results list	
	resultsList::iterator emptyIter = resultsList.begin();
	++emptyIter;

	//create an iterator pointing at the most recently added prime in the searchList
	searchList::iterator primeIter = results.begin();
	++primeIter;
	++primeIter;

	bool done = false;

	//main loop
	while( !done )
	{
		for_each( resultsList.begin() , resultsList.end() , [&mySearchList]( int prime )
		{
			for_each( primeIter , mySearchList.end() , [ prime ]( primeMember * pM )
			{
				if( pM->_isPrime )
				{
					if( pM->_value % prime == 0 )
						pM->_isPrime == false;				
				} 
			} );

		} );

		//the next primeMember listed as prime is the next prime number and it should be added to the result list 
		auto pos = find_if( primeIter , resultsList.end() , []( primeMember * pM )
		{
			return pM->_isPrime == true;
		} );
		
		//check if anything found
		if( pos == resultsList.end() )
			done = true;
		else
		{
			primeIter = pos;
			searchList[pos]->_isPrime = false;
			resultsList[emptyIter] = searchList[pos]->_value;
			++emptyIter;
	
			//check if empty Iter is at the end, if so add some more space to the results list
			if( emptyIter == resultsList.end() )
				resultsList.resize( ( resultsList.size() + 1000 ) , int prime(0) );
		}
	}	
}

