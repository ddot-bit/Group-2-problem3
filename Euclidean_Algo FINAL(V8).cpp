/**************************************************************************
//
// Group: Diego Puducay
//        Shinda Huang
//
// Course: Math 22
// Assignment: Group Work 2
// Problem Number: #3
//
// NOTE:
// Dumped core is probably intiated by the variable "b" dividing by zero.
//
// EDIt:
// Dumped core memory issue was caused by the while loop enacting two
// actions at once; resoved with the "break" lexicon.
//
//************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// This program attempts to disply the extended Eucledian algorithm interatively (not recursively) via the quotient remainder theorem.
void display_initial_values(int a, int b, int s, int t, int u, int v, int gcd);

void output_heading();
void extd_eucluid_algo(int A, int B, int a, int b, int r, int q, int s, int t, int u, int v, int new_u, int new_v, int gcd);

void output(int index, int size, int out_a[], int out_b[], int out_r[], int out_q[], int out_s[], int out_t[], int out_u[], int out_v[], int out_new_u[], int out_new_v[], int out_gcd[]);

int main()
{
   // Desired integers (initial values).
   int A = 330;
   int B = 156;
   int s = 1, t = 0, u = 0, v = 1;
   int new_u = 0;
   int new_v = 0;
   int q = 0;
   int r = 0;
   int gcd;
   int a, b;
   a = s * A + t * B;
   gcd = a;
   b = u * A + v * B;

   // Need to output inital values prior to iteratons.
   display_initial_values(a, b, s, t, u, v, gcd);

   output_heading();

   // Output function is called within the eucledian_algo function.
   extd_eucluid_algo(A, B, a, b, r, q, s, t, u, v, new_u, new_v, gcd);

   return 0;

}

void extd_eucluid_algo(int A, int B, int a, int b, int r, int q, int s, int t, int u, int v, int new_u, int new_v, int gcd)
{

   int index = 0;
   const int size = 15;

   int out_r[size];
   int out_q[size];
   int out_a[size];
   int out_b[size];
   int out_new_u[size];
   int out_new_v[size];
   int out_s[size];
   int out_t[size];
   int out_u[size];
   int out_v[size];
   int out_gcd[size];

   // via given algorithm from assignment
   a = A;
   b = B;

   //a = s * A + t * B;
  //b = u * A + v * B;

   while (B != 0)
   {
      r = a % b; //remainder
      q = a / b; // quotient

      a = b;
      b = r;

      // rewrittern form of the euclidan algo.
      new_u = s - u * q;

      new_v = t - v * q;

      s = u;
      t = v;

      u = new_u;
      v = new_v;

      // build solution
      gcd = s * a + t * b;

      // stored in arrays for constructing output table
      out_r[index] = r;
      out_q[index] = q;
      out_a[index] = a;
      out_b[index] = r;
      out_new_u[index] = new_u;
      out_new_v[index] = new_v;
      out_s[index] = s;
      out_t[index] = t;
      out_u[index] = u;
      out_v[index] = v;
      out_gcd[index] = gcd;

      if (b == 0)
      {
         // check if the gcd does = a
         // should be gcd = a * 1 + t * 0;

         gcd = s * A + t * B;
         out_gcd[index] = gcd;

         // call output subfunction for output
         output(index, size, out_a, out_b, out_r, out_q, out_s, out_t, out_u, out_v, out_new_u, out_new_v, out_gcd);
         break;
      }
      index++;
   }
}

void display_initial_values(int a, int b, int s, int t, int u, int v, int gcd)
{
   int n = -1; // to differentiate null values and the integer 0.
   string index_array[12] = { "a", "b", "r", "q", "s", "t", "u", "v", "new u", "new v","sa + tb", "null" };
   int initial_values[11] = { a, b, n, n, s, t, u, v, n, n, gcd };

   for (int i = 0; i < 80; i++)
   {
      cout << "-";
   }
   cout << endl << endl;
   cout << left << setw(29) << " " << "Initial Values\n" << right << endl;

   for (int i = 0; i < 80; i++)
   {
      cout << "-";
   }
   cout << endl;

   for (int i = 0; i < 11; i++)
   {

      cout << "\t|" << endl;
      cout << index_array[i] << "\t|";
      if (initial_values[i] == n)
      {
         cout << index_array[11] << "\t\n";
      }
      else if (initial_values[i] != n)
      {
         cout << initial_values[i] << "\t";
         cout << endl;
      }
   }

   cout << "\t|" << endl;

}

void output_heading()
{
   for (int i = 0; i < 80; i++)
   {
      cout << "-";
   }

   cout << endl << endl;
   cout << left << setw(20) << " " << "Extended Eucledian Algorithm Table\n" << right << endl;

   for (int i = 0; i < 80; i++)
   {
      cout << "-";
   }
   cout << endl << "\t|" << endl;

}

// Note: I redifined the inital values locally in this subfunction because it was easier to do and there were no
// restrictions on how to pass values for the program.
void output(int index, int size, int out_a[], int out_b[], int out_r[], int out_q[], int out_s[], int out_t[], int out_u[], int out_v[], int out_new_u[], int out_new_v[], int out_gcd[])
{
   int A = 330;
   int B = 156;
   int s = 1, t = 0, u = 0, v = 1;
   int gcd = 330;
   string n = "Null";
   string index_array[11] = { "a", "b", "r", "q", "s", "t", "u", "v", "new u", "new v","sa + tb" };

   cout << index_array[0] << "\t|" << A << "\t";

   for (int j = 0; j < index + 1; j++)
   {
      cout << out_a[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[1] << "\t|" << B << "\t ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_b[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[2] << "\t|" << n << "\t ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_r[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[3] << "\t|" << n << "\t  ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_q[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[4] << "\t|" << s << "\t  ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_s[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[5] << "\t|" << t << "\t  ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_t[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[6] << "\t|" << u << "\t  ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_u[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[7] << "\t|" << v << setw(9);
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_v[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[8] << "\t|" << n << "\t  ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_new_u[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[9] << "\t|" << n << "\t ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_new_v[j] << setw(8);
   }

   cout << endl << "\t|" << endl;


   cout << index_array[10] << "\t|" << gcd << "\t ";
   for (int j = 0; j < index + 1; j++)
   {
      cout << out_gcd[j] << setw(8);
   }
   cout << endl << "\t|" << endl;


   for (int i = 0; i < 80; i++)
   {
      cout << "-";
   }
   cout << endl << endl;
}