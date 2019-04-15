/*Triangle
	A
  B	  C
*/
#include<iostream>
using namespace std;

int hanoiNumber;	// height of hanoi tower

bool CheckMove(int, int, int **);
void Move(int, int, int, int, int **);
void PrintArr(int**);
bool checkValid;		//vaild

int main()
{
	cin >> hanoiNumber;

	int **firstArr = new int*[3];
	int **goalArr = new int*[3];
	int **currentArr;

	// init rows
	for (int i = 0; i < 3; i++)
	{
		firstArr[i] = new int[hanoiNumber];
		goalArr[i] = new int[hanoiNumber];

	}
	// init columns
	for (int i = 0; i < hanoiNumber; i++)
	{
		firstArr[0][i] = hanoiNumber - i;
		goalArr[2][i] = hanoiNumber - i;
	}

	for (int i = 1; i < 3; i++)
		for (int j = 0; j < hanoiNumber; j++)
			firstArr[i][j] = 0;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < hanoiNumber; j++)
			goalArr[i][j] = 0;
	currentArr = firstArr;

	int number = 0;
	int indexOfOne = 0;

	while (true)
	{
		int cnt = 0;
		//check goalstate
		for (int i = 0; i < hanoiNumber; i++)
		{
			if (currentArr[2][i] == goalArr[2][i]) cnt++;
		}
		
		if (cnt == hanoiNumber) {
			break;
		}
		else {
			cout <<"number : " <<number << endl;
			if (number % 2 != 0)
			{
				
				//odd number
				if (hanoiNumber % 2 != 0)
				{
					//odd numberhanoi
					//go clockwise
					checkValid = CheckMove(indexOfOne, (indexOfOne + 2) % 3, currentArr);
					PrintArr(currentArr);
					indexOfOne = (indexOfOne + 2) % 3;
				}
				else
				{
					//even numberhanoi
					//go counterclockwise
					checkValid = CheckMove(indexOfOne, (indexOfOne + 1) % 3, currentArr);
					PrintArr(currentArr);
					indexOfOne = (indexOfOne + 1) % 3;
				}


			}
			else
			{
				//even number
				checkValid = CheckMove((indexOfOne + 1) % 3, (indexOfOne + 2) % 3, currentArr);
				if(checkValid) PrintArr(currentArr);
				else
				{
					CheckMove((indexOfOne + 2) % 3, (indexOfOne + 1) % 3, currentArr);
					PrintArr(currentArr);
				}
			}
			number++;
			
		}
	}

	return 0;
}

bool CheckMove(int i, int j, int **arr) {
	int from;
	int to;

	// start: [i,from]
	for (from = hanoiNumber - 1; from >= 0; from--)
		if (arr[i][from] != 0) break;

	// arrive: [j,to]
	for (to = hanoiNumber - 1; to >= 0; to--)
		if (arr[j][to] != 0) break;
	to++;

	// do not start
	if (from < 0) {
		return false;
	}

	// index of arrive is not 0, check idx-1
	if (to != 0) {
		if (arr[j][to - 1] <= arr[i][from]) {
			return false;
		}
	}
	Move(i, j, from, to, arr);
	return true;
}

void Move(int i, int j, int from, int to, int **arr)
{
	int temp = arr[i][from];
	arr[j][to] = temp;
	arr[i][from] = 0;
}

void PrintArr(int **a) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < hanoiNumber; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}