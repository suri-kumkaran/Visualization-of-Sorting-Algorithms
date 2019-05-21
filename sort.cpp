//suri_kumkaran
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define width	500
#define height  500

using namespace std;

string comparisontext = "No. of Comparisons";
string sort_name;
int comparison_count;
vector<int> arr(500);

// Function for displaying Text
void displayText(float x ,float y,string stringToDisplay) 
{
	int len;
	glRasterPos2f(x, y);
        len = stringToDisplay.length();
	for(int i=0 ;i<len ;i++)
        {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,stringToDisplay[i]);
	}
}

// Display Initialization
void init()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
}

// This Function plot the sample array
void drawbar(vector<int> arr)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	displayText(190,470,sort_name);
	displayText(150,430,"No. of Comparisons = "+to_string(comparison_count));
	glColor3f(1.0,0.0,0.0);
	int x=0;
	for(int i=0; i<arr.size(); i++)
	{
		glRecti(x,0,x+1,arr[i]);
		x+=1;
	}
	glFlush();
	usleep(100);
}
//Structure of Quicksort 
struct Quicksort
{
	int findpivot(vector<int> &, int,int,int);
	int partition(vector<int> &, int, int);
	void quicksort(vector<int> &, int,int);
};

//This function decide pivot for quick sort
int Quicksort::findpivot(vector<int> &sample, int left, int mid, int right)
{

	comparison_count++;
	drawbar(sample);
	if((sample[left]>=sample[mid]&&sample[left]<=sample[right])||
	  	(sample[left]<=sample[mid]&&sample[left]>=sample[right]))
		return left;

	comparison_count++;
	drawbar(sample);
	if((sample[mid]>=sample[left]&&sample[mid]<=sample[right])||
  		(sample[mid]<=sample[left]&&sample[mid]>=sample[right]))
		return mid;

	comparison_count++;
	drawbar(sample);
  	if((sample[right]>=sample[mid]&&sample[right]<=sample[left])||
		(sample[right]<=sample[mid]&&sample[right]>=sample[left]))
		return right;
		return right;
}

// This Function do partition according to pivot
int Quicksort::partition(vector<int> &sample,int left,int right)
{
	int p=findpivot(sample,left,(left+right)/2,right);
	swap(sample[left],sample[p]);
	drawbar(sample);
	p=sample[left];
	int i=left+1;
	int j=left+1;
	for(;i<=right;i++)
	{
		comparison_count++;
		if(sample[i]<p)
		{
			swap(sample[i],sample[j]);
			j++;
		}
		drawbar(sample);
	}
	swap(sample[left],sample[j-1]);
	drawbar(sample);
  return j-1;
}

/*This function divide the partitioned sample 
and again call the quicksort function reccursively*/
void Quicksort::quicksort(vector<int> &sample,int left,int right)
{
  if(right>left)
  {
    int p=partition(sample,left,right);
    quicksort(sample,left,p-1);
    quicksort(sample,p+1,right);
  }
}

// Struct for Selection Sort
struct SelectionSort
{
	void selectionsort(vector<int> &);
};

// This Function do sorting by selecting minimum element and putting it at front
void SelectionSort::selectionsort(vector<int> &sample)  
{  
	drawbar(sample);
    int i,j,min_idx;
    int n=sample.size();  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++) 
        { 
        	if (sample[j] < sample[min_idx])  
            	min_idx = j;

            comparison_count++;
            drawbar(sample);  
        }
        swap(sample[min_idx],sample[i]);
        drawbar(sample);
    }
    drawbar(sample);  
}

//Structure for bubbleSort
struct BubbleSort
{
	void bubblesort(vector<int> &);
};														


// This Function sort the sample by bubbling largest element at the right
void BubbleSort::bubblesort(vector<int> &sample) 
{ 
   drawbar(sample);
   int i, j; 
   int n = sample.size();
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (sample[j] > sample[j+1]) 
        { 
           swap(sample[j], sample[j+1]); 
           swapped = true; 
        }
        comparison_count++;
        drawbar(sample); 
     } 

     if (swapped == false) 
        break; 
   }
   drawbar(sample);
}

//Structure for MergeSort
struct MergeSort
{
  void merge(vector<int> &, int, int, int);
  void mergesort(vector<int> &, int, int);
};

//This Function Merges two sorted sample comparing their value
void MergeSort::merge(vector<int> &sample, int l, int m, int r) 
{ 
	drawbar(sample);
    int i, j, k; 
    int n1 = m - l + 1;
    int n2 =  r - m; 
  
    int l_sample[n1], r_sample[n2]; 
  
    for (i = 0; i < n1; i++) 
        l_sample[i] = sample[l + i]; 
    for (j = 0; j < n2; j++) 
        r_sample[j] = sample[m + 1+ j]; 
  
    i = j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (l_sample[i] <= r_sample[j]) 
        { 
            sample[k] = l_sample[i]; 
            i++; 
        } 
        else
        { 
            sample[k] = r_sample[j]; 
            j++; 
        } 
        k++;

        comparison_count++;
        drawbar(sample);
    } 
  
    while (i < n1) 
    { 
        sample[k] = l_sample[i]; 
        i++; 
        k++;
        comparison_count++;
        drawbar(sample);
 
    } 

    while (j < n2) 
    { 
        sample[k] = r_sample[j]; 
        j++; 
        k++;
        comparison_count++;
        drawbar(sample);
 
    }
    drawbar(sample);
} 
  
// This function sort the sample by calling recursively on two halves 
//and then calling merge to merge them
void MergeSort::mergesort(vector<int> &sample, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergesort(sample, l, m); 
        mergesort(sample, m+1, r); 
        merge(sample, l, m, r); 
    } 
}

//This is our display funtion which call different sorting algorithms one by one
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	vector<int> temp ;

	temp=arr;
	Quicksort my_qsort;
	comparison_count = 0;
	sort_name = "Quick Sort";
	my_qsort.quicksort(temp,0,temp.size()-1);
	sleep(2);

	temp=arr;
	SelectionSort my_selsort;
	comparison_count = 0;
	sort_name = "Selection Sort";
	my_selsort.selectionsort(temp);
	sleep(2);

	temp=arr;
	BubbleSort my_bubsort;
	comparison_count = 0;
	sort_name = "Bubble Sort";
	my_bubsort.bubblesort(temp);
	sleep(2);

	temp=arr;
	MergeSort my_mergesort;
	comparison_count = 0;
	sort_name = "Merge Sort";
	my_mergesort.mergesort(temp,0,temp.size()-1);
	sleep(2);
}


int main(int argc, char **argv)
{
	srand(time(NULL));
	cout <<"Generating random numbers\n";

	for(int i=0; i<arr.size(); i++)
		arr[i] = rand()%400;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("Visualization of Sorting Algorithms");
	glutDisplayFunc(display);
	init();
	gluOrtho2D(0,width,0,height);
	glutMainLoop();
}
