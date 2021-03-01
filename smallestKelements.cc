// C++ program to find k-th smallest 
// element in Min Heap using another 
// Min Heap (Or Priority Queue) 
#include <iostream> 
#include <vector> 
#include <utility> 
#include <algorithm> 
#include <functional>
#include <queue> 
using namespace std; 

// Structure for the heap 
struct Heap { 
	vector<int> v; 
	int n; // Size of the heap 

	Heap(int i = 0) 
		: n(i) 
	{ 
		v = vector<int>(n); 
	} 
}; 

// Returns the index of 
// the left child node 
inline int left(int i) 
{ 
	return 2 * i + 1; 
} 

// Returns the index of 
// the right child node 
inline int right(int i) 
{ 
	return 2 * i + 2; 
} 

vector<int> findKthSmalles(Heap &h, int k) 
{ 
	// Create a Priority Queue 
	priority_queue<pair<int, int>, 
				vector<pair<int, int> >, 
				greater<pair<int, int> > > 
		p; 

	// Insert root into the priority queue 
  	vector<int> a;
	p.push(make_pair(h.v[0], 0)); 

	for (int i = 0; i < k ; ++i) { 
		int j = p.top().second; 
      	a.push_back(p.top().first);
		p.pop(); 
		int l = left(j), r = right(j); 
		if (l < h.n) 
			p.push(make_pair(h.v[l], l)); 
		if (r < h.n) 
			p.push(make_pair(h.v[r], r)); 
	} 

	return a; 
} 

int main() 
{ 
	Heap h(7); 
	//h.v = vector<int> { 10, 50, 40, 75, 60, 65, 45};
	h.v.clear(); 
	h.v.push_back(10);
	h.v.push_back(50);
	h.v.push_back(40);
	h.v.push_back(75);
	h.v.push_back(60);
	h.v.push_back(65);
	h.v.push_back(45);
	cout<<"All the elements are: "<<endl;
	int k = 4;
	for (auto i = h.v.begin(); i != h.v.end(); ++i) 
        cout << *i << " ";  
    	cout<<endl;
    	cout<<"The four smallest elements are: "<<endl;
  	vector<int> l = findKthSmalles(h, k);
  	for (auto i = l.begin(); i != l.end(); ++i) 
        cout << *i << " "; 
    	cout<<endl;
	return 0; 
} 
