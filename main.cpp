    #include <iostream>
    #include <math.h>
    #include <string>
    #include <fstream>
    using namespace std;
	float * variance_impurity(char vec[600][21] , int row, int col);
	void split_tree(char vec[600][21],int row,int col,int max);

    int main()
    {
         const int rows = 600;
        const int cols = 41;
        ifstream file("training_set2.csv");
        if (file.is_open())
		{
            char r[rows][cols];
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j)
		{
		    	file >> r[i][j];
                }
            }
		char l[600][21];
	    for(int i = 0;i < 600;i++)
		{
			for (int j=0 ; j< 21;j++ )
			{
				if (j ==21)
				{
				l[i][j]=r[i][41];
				}
			l[i][j]=r[i][2*j];
			}
		}

               int row =  sizeof l / sizeof l[0];
               int col  = sizeof l[0] / sizeof(char);
	       float * info_gain = variance_impurity(l,row,col);
		for (int i = 0;i<21; i++)
		{
		cout<< info_gain[i] <<" " ;
		}
//		split_tree(l,row,col,3);
        }
    }


// ab splitting scene karke dikhao
void split_tree(char vec[600][21],int row,int col,int max)
{
// determine the size of the new tables. Number of zeros and ones and the column is one less
int number_of_ones=0;
int number_of_zeros =0;
	for (int i = 0 ; i < col ; i++ )
	{
		if (vec[i][max] == '1')
		{
		 number_of_ones ++;
		}
		else if(vec[i][max] == '0')
		{
		number_of_zeros ++;
		}
	}
	char split_1[number_of_ones][col-1];
	char split_2[number_of_zeros][col-1];

// copy the values to make new tables
int l=0;
	for (int i=0;i < row;i++)
	{
	int k=0;
	 for (int j=0;j < col-1 ;j++)
		{
			k=j;
			if ( j == max)
			{
			k=k+1;
			}

			if (vec[i][j] == '1')
			{
			split_1[l][j] = vec[i][k];
			l++;
			}
		}
	}
	for (int i = 0; i< 200; i++)
	{
		for (int j =0; j < 20; j++)
		{
		cout<< split_1[i][j] ;
		}
	}


}




float * variance_impurity(char vec[600][21] ,int row,int col)
{

float table[11][col];
	for (int i =0; i < col; i++ )
	{
	int ones_in_attr = 0;
	int zeros_in_attr = 0;
		for (int j=0; j < row; j++ ) // change j and i to make it generic everywhere i is the number of features
		{
			if (vec[j][i] == '1')
			{
				ones_in_attr++;
			}
			else if (vec[j][i] == '0')
			{
				zeros_in_attr++;
			}
		}
	table[1][i] = ones_in_attr;
	table[2][i] = zeros_in_attr;
	float a =  table[1][i]/(table[1][i]+table[2][i]);
	float b =  table[2][i]/(table[1][i]+table[2][i]);
	table[3][i]= ((-1*a*log(a))-(b*log(b))); // entropy in the attribute
	}

        for (int i =0; i < col; i++)
        {
	int ones_in_attr_corr_class = 0;
	int zeros_in_attr_corr_class = 0;
                for (int j=0; j < 600; j++ )
                {
                        if (vec[j][i] == '1' && vec[j][col-1]== '1')
                        {
                                ones_in_attr_corr_class++;
                        }
                        else if (vec[j][i] == '0' && vec[j][col-1]=='0')
                        {
                                zeros_in_attr_corr_class++;
                        }
                }
        table[4][i] = ones_in_attr_corr_class;
        table[5][i] = (table[1][i] - ones_in_attr_corr_class);
        float c =  table[4][i]/(table[4][i]+table[5][i]);
        float d =  table[5][i]/(table[4][i]+table[5][i]);
        table[6][i] = ((-1*c*log(c))-(d*log(d))); // entropy in the ones

	table[7][i] = zeros_in_attr_corr_class;
	table[8][i] = (table[2][i] - zeros_in_attr_corr_class);
        float e =  table[7][i]/(table[7][i]+table[8][i]);
        float f =  table[8][i]/(table[7][i]+table[8][i]);
 	table[9][i] =((-1*e*log(e))-(f*log(f))); // entropy in the zeros

	table[10][i]= table[3][i] - ((table[2][i]/(table[2][i]+table[3][i]))*table[6][i]) - ((table[3][i]/(table[2][i] + table[3][i]))*table[9][i]); // information gain in the system
        }
	float Info_gain[col];
	for (int h =0 ; h<col ; h++)
	{
	Info_gain[h]= table[10][h];
	}
return Info_gain;

}


