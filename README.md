# pal_canalinspection
B4M33PAL homework, assignment: https://cw.felk.cvut.cz/courses/a4m33pal/task.php?task=canalsinspection

```
Leaking canals inspection

Lakes in Lake district are connected by canals. The canals were built decades ago, many of them are poorly maintained and there is a concern that significant leaks may occur in those canals soon. The management of Lake district has created a list of canals which in their opinion are most affected by ageing and established a committee which is going to inspect those canals. 
The committee has hired an inspection barge and they plan to sail through the lakes and canals to asses and report the state of the canals on the list. If necessary, a road transporter can carry the barge to any lake where the inspection journey will begin. The transporter will not be available later, therefore the barge is not expected to leave the waterways during the inspection. The barge might finish its journey on any lake. 
Traveling through canals in Lake district is limited by the fact that all canals are one-way waterways. Each canal connects two different lakes, each lake can be a start point of none, one or more than one canal and also it can be an end point of none, one or more than one canal. 
It is possible that under these limited conditions the committee will not be able to inspect all the affected canals and that some of the canals will remain uninspected. Nevertheless, the committee wants to maximize the number of canals on the list which can be reached during the journey. The barge can travel relatively fast, so it does not matter if it sails through some lakes or canals more than once.

     


Image 1. Example of scheme of the canals in Lake district. The scheme depicts the data in Example 1 bellow. The nodes correspond to the lakes, the affected canals which deserve inspection are depicted by bold blue arows and the unaffected canals are depicted by black thinner arrows. The barge can visit at most 7 affected canals in one journey. For example, it can travel via corresponding canals through lakes 5, 10, 9, 4, 5, 11, 12, 6, 11, 12, 13, 7, 8, 13.

The task

You are given a scheme of the lakes and canals in Lake district with marked affected canals which need inspection. Calculate the maximum number of affected canals which can be visited during one journey along the waterways respecting the travel conditions given above.

Input

The first line of input contains two integers N, M separated by space. N represents the nuber of the lakes, M represents the number of the canals. The lakes are labeled 0, 1, ..., N−1. Next, there are M text lines, each specifies one canal. The line contains three integers a, b, c separated by spaces, a is the label of the start lake of the canal, b is the label of the end lake of the canal and c has value 1 or 0. The value 1 indicates that the canal is affected and needs to be inspected, the value 0 indicates that the canal is unaffected. 
It holds, 0 < N ≤ 105, 0 < M ≤ 106.

Output

The output consists of a single text line containing one integer equal to the maximum number of affected canals which can be visited during one journey through the given waterways.

Example 1

Input
14 21
5 1 1
1 0 0
0 2 0
2 1 1
2 3 0
3 8 1
4 5 0
5 6 1
7 8 0
10 9 0
10 11 0
11 12 0
12 13 1
9 4 1
5 10 1
5 11 1
6 11 1
12 6 1
12 7 0
13 7 0
8 13 1
Output
7
The data of Example 1 are depicted in Image 1 above.        
Example 2

Input
10 13
0 1 0
1 2 0
2 3 0
3 4 0
5 6 0
6 7 0
7 8 0
8 9 0
0 5 1
6 1 1
2 7 1
8 3 1
4 9 1
Output
5


 	

Image 2. The scheme of the waterways in Example 2.
       
Example 3

Input
10 11
0 1 0
5 6 0
7 6 1
7 8 1
9 8 0
3 0 1
1 3 1
2 5 1
6 2 0
8 4 0
4 9 0
Output
2



 	

Image 3. The scheme of the waterways in Example 3.
Public data

The public data set is intended for easier debugging and approximate program correctness checking. The public data set is stored also in the upload system and each time a student submits a solution it is run on the public dataset and the program output to stdout and stderr is available to him/her. 
Link to public data set
```
