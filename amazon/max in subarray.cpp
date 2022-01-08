 vector<int> res;
        deque<int> q;

        int i = 0;
        for (i = 0; i < k; i++) {

            while ((!q.empty()) && (arr[i] >= arr[q.back()])) q.pop_back();

            q.push_back(i);
        }

        for (; i < n; i++) {

            res.push_back(arr[q.front()]);

            while ((!q.empty()) && (q.front() <= i - k)) q.pop_front();

            while ((!q.empty()) && (arr[i] >= arr[q.back()])) q.pop_back();

            q.push_back(i);
        }

        res.push_back(arr[q.front()]);
        q.pop_front();

        return res;


        /*
        in dequeue we are storing the maximum element index in front. So that the we can get max element in
        O(1).

        we remove index from front when it's not in the range of k.

        we remove index from back when element at index i is greater than them ,so that only have index 
        which is greater than all .
         
        

        
        */