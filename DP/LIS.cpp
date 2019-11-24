int lis(vector<int> arr) {
   set<int> st;
   for(int i=0;i<arr.size();i++){
       auto it = st.upper_bound(arr[i]);
       if(it==st.end()){
           st.insert(arr[i]);
       }else{
           st.erase(it);
           st.insert(arr[i]);
       }
   }
   return st.size();
}