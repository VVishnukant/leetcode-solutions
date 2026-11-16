class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int j = 0;
        int n = students.size();
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int count = 0;
        while(count!=q.size()){
            if(q.front()==sandwiches[j]){
                count = 0;
                q.pop();
                j++;
            }
            else {
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};