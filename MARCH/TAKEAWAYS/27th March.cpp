SLIDING WINDOW TEMPLATE

        int i=0;
        int j=0;
        int prod=1;
        while(j<n){
            prod*=nums[j];
            while(prod>=k){ //untill condition violates remove ith index
             prod/=nums[i];
             i++;

            }

            // now condition is valid
            count+=j-i+1;//no. of subarrays ending at j
            j++;
        }
