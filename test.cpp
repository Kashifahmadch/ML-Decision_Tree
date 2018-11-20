#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

using vec = vector<string>;
using matrix = vector<vec>;

//======================================================================

matrix readCSV(string filename)
{
   char separator = ',';
   matrix result;
   string row, item;

   ifstream in( filename );
   while( getline( in, row ) )
   {
      vec R;
      stringstream ss( row );
      while ( getline ( ss, item, separator ) ) R.push_back( item );
      result.push_back( R );
   }
   in.close();
   return result;
}

//======================================================================

//void printMatrix( const matrix &M )
//{
//   for ( vec row : M )
//   {
//      for ( string s : row ) cout << setw( 12 ) << left << s << " ";    // need a variable format really
//      cout << '\n';
//   }
//}


int main()
{
   matrix pets = readCSV( "training_set.csv" );
//   printMatrix( pets );

   cout << "\n\n";
}
