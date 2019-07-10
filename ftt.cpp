#include<iostream> 
#include<vector>


# define M_PI   3.14159265358979323846
using namespace std; 

#include<math.h>





vector<int>	vector1;
vector<int> even_vector; 
vector<int> odd_vector;
vector<int> temping_even;
vector<int> temping_odd;

pair<double, double > complex; 
vector<pair<double, double >> vectp; 
vector<pair<double, double >> vectemp;
vector<pair <double, double>> wvector; 

//vector<int, int > vector_temp; 

int vector_size;
int vector_half; 
int vector_quad; 



void initializing(int k) // to initializing the vectors with data and main information  
{
	complex.first = 0;
	complex.second = 0;
	
	for (int i = 0; i < k; i++)
	{
		
		vectp.push_back(complex); 
		vectemp.push_back(complex);

	}

	for (int i = 0; i < k*2; i++)
	{

		wvector.push_back(complex);

	}


	for (int i = 0; i < k; i++)
	{
		vector1.push_back(0);  // make the first vector for input data 

	}

	for (int i = 0; i < k/2; i++)  // initialize the two vectors for even data and odd 
	{
		temping_even.push_back(0);
		temping_odd.push_back(0);
	}


	vector_size = vector1.size();   // main information about data and measurments 
	vector_half = vector_size / 2;
	vector_quad = vector_half / 2;

	


}


void pushin_vector()    // pushing the input data in vector 1 
{

	int y= 0; 

	for (int i = 0 ; i < vector1.size(); i++)
	{
		 cin>>y;
		 vector1[i] = y;
		y++;
		
	}

	for (int i = 0; i < vector1.size(); i++)
	{
		cout << vector1[i]<<endl; 
		 
	}
	cout << endl;
}



void devided()                   // devide the input to two vectors even and odd 
{ 

	for (int i = 0; i < vector_size; i += 2)   // even vector 
	{
		even_vector.push_back(vector1[i]);
		cout << vector1[i]<<endl;
	}

	cout << endl;

	for (int i = 1; i < vector_size ; i += 2) // odd vector 
	{
		odd_vector.push_back(vector1[i]);
		cout << vector1[i]<<endl;
	}

	cout << endl; 

}

 double no_pro;

void logging()   // to know a number of how many levels in products 
{


	no_pro = log2(vector_size);
	cout << no_pro - 1<<endl<<endl ;
}

void swapping()   //  to swapping the inputs and devide data in new index  
{
	double  q=0,iter = 1; 
	int k = 0, g = 0 , m = vector_size, n=0,t=0;

	for (int j = 0; j < no_pro-1; j++)
	{   

	
		q = pow(2, t);
		t++;
		iter = pow(2,j+1) ;
		k = 0;
		m =m / 2;
		n = 0;
		for (int w = 0; w <q ; w++)
		{

			for (int i = 0+n; i < (vector_half/q)+n; i += 2)
			{
				temping_even[k] = even_vector[i];
				temping_odd[k] = odd_vector[i];

				k++;
			}


			for (int i = 1+n; i < (vector_half/q)+n; i += 2)
			{
				temping_even[k] = even_vector[i];
				temping_odd[k] = odd_vector[i];

				k++;
			}
			n+=m; 

			even_vector = temping_even;
			odd_vector = temping_odd;
		}
		
		
	}
	

	for (int i = 0; i < vector_size/2; i++)
	{
		vector1[i] = temping_even[i];
	}
	
	for (int i = vector_size/ 2 ,  k = 0 ; i < vector_size , k < vector_size/2 ; i++,k++)
	{
		vector1[i] = temping_odd[k];
	}


}


void weight(int level)
{
	double wl, wh, f;
	int n = 0;

	f = pow(2, level);

	for (int i = 0; i <f; i++)
	{

		wh = cos(2 * M_PI*n / (f *2));
		wl = sin(2 * M_PI*n / (f *2))*-1;

		wvector[i].first = wh;
		wvector[i].second = wl;
		n++;

	}
	n = 0;


}


void weight22(int level)
{
	double wl, wh, f;
	int n = 0;

	f = pow(2, level);

	for (int i = 0; i <f; i++)
	{

		wh = cos(2 * M_PI*n / vector_size);
		wl = sin(2 * M_PI*n / vector_size)*-1;

		wvector[i].first = wh;
		wvector[i].second = wl;
		n++;

	}
	n = 0;


}


void products()
{ 

	for (int i = 0; i < vector_size; i++)
	{
		vectp[i].first = vector1[i]; 
		vectp[i].second = 0; 
	}

	int level = -1 ,level2 =0 ,level3=0 ,  edge , edge2,edge3, m=0,n=0;
	int inc=0, inc2, dec=-1; 
	double ww; 

	for (int i = 0; i < no_pro; i++)
	{  
	    	edge2 = pow(2, ++level2 );	
	    	edge = pow(2, ++level  );
		   weight(i);
			//weight22(i);
			m = 0;
			edge3 = pow(2, ++level3);

		for (int j = 0; j < vector_size/edge2; j++)
		{
			

			for (int k = 0+m; k < edge+m; k++ )
			{
				inc = k + edge; 
				// real product      w*B 
				complex.first=((vectp[inc].first * wvector[n].first) + (vectp[inc].second * wvector[n].second)); 
				// imagine product   W*B
				complex.second = ((vectp[inc].first * wvector[n].second) + (vectp[inc].second * wvector[n].first));

				//vectp[inc].first = complex.first; 
				//vectp[inc].second = complex.second; 

				////a+wb   real 
				//vectemp[k].first = (vectp[inc].first + vectp[k].first  );
				////a+wb   img 
				//vectemp[k].second= (vectp[inc].second + vectp[k].second);



			

				//a+wb   real 
				vectemp[k].first = (complex.first + vectp[k].first);
				//a+wb   img 
				vectemp[k].second = (complex.second + vectp[k].second);

				n++;
			}
			n = 0;

			for (int j = edge+m; j < (2*edge)+m; j++)
			{
				dec = j - edge;
				// real product      w*B 
				complex.first = ((vectp[j].first * wvector[n].first) + (vectp[j].second * wvector[n].second))*-1;
				// imagine product   W*B
				complex.second = ((vectp[j].first * wvector[n].second) + (vectp[j].second * wvector[n].first))*-1;

				//vectp[j].first = complex.first;
				//vectp[j].second = complex.second;
				////a+wb   real 
				//vectemp[j].first = (vectp[dec].first + vectp[j].first);
				////a+wb   img 
				//vectemp[j].second = (vectp[dec].second + vectp[j].second);


				
				//a+wb   real 
				vectemp[j].first = (vectp[dec].first + complex.first);
				//a+wb   img 
				vectemp[j].second = (vectp[dec].second + complex.second);


				n++;
				
			}
			n = 0; m += edge3;
		}
		vectp = vectemp;

		for (int i = 0; i < vectp.size(); i++)
		{
			cout << vectp[i].first << " +j " << vectp[i].second << endl;
			
		}
		cout << "--------------------------------------------------------" << endl<<endl;
	}
	
}








int main()
{


	int u; 
	cout << "enter the number"; 
	cin >> u; 

	 
	initializing(u);
	pushin_vector();
	devided();
	logging();
	swapping();


	for (int i = 0; i < vector1.size(); i++)
	{
		cout << vector1[i] << endl;
	}
	cout << endl << endl;


	products();



	for (int i = 0; i < vectp.size(); i++)
	{
		cout << vectp[i].first<<" +j "<<vectp[i].second << endl;
	}


	
	
	


	cin >> u; 
	return 0; 
}