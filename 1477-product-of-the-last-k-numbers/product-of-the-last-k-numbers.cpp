class ProductOfNumbers {
private:
    vector<int> prefix; 

public:
    ProductOfNumbers() {
        prefix.push_back(1); 
    }

    void add(int num) {
        if (num == 0) {
            
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(num * prefix.back());
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            return 0; 
        }
        return prefix.back() / prefix[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */