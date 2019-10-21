/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

// Variant 1
// recursion to traverse
// prev,curr number comparasion
// force return
void traverse(Node* curr, int &num) {
    if (num == -1)
        return;
    
    if(curr->left) {
        traverse(curr->left, num);
        
        if (num == -1)
            return;        
    }
    
    if(curr->data > num)
        num = curr->data;
    else {
        num = -1;        
        return;
    }
        
    if(curr->right) {
        traverse(curr->right, num);
            
        if (num == -1)
            return;  
    }
}


bool checkBST(Node* root) {
    int num = 0;
    
    traverse(root, num);
    
    return num != -1 ? true: false;
}

/* 
// Variant 2
// recursion to traverse
// making vector
// is_sorted
template <class ForwardIt, class Compare>
ForwardIt is_sorted_until(ForwardIt first, ForwardIt last, Compare comp) {
    if (first != last) {
        ForwardIt next = first;
        while (++next != last) {
            if (comp(*next, *first))
                return next;
            first = next;
        }
    }
    return last;
}

struct less_equeal {
    template<typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const {
        return lhs <= rhs;
    }
};

template<class ForwardIt>
ForwardIt is_sorted_until(ForwardIt first, ForwardIt last) {
    return is_sorted_until(first, last, less_equeal());
}

void traverse(Node* curr, std::vector<int> & vec) {
    if(curr->left)
        traverse(curr->left, vec);
    
    vec.push_back(curr->data);
        
    if(curr->right)
        traverse(curr->right, vec);
}

bool checkBST(Node* root) {
    std::vector<int> vec;
    
    traverse(root, vec);
    
    if(is_sorted_until(begin(vec), end(vec)) == end(vec))
        return true;
    else
        return false;
}
*/
