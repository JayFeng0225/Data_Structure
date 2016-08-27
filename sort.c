#include <stdio.h>
#include <stdlib.h>


#define SWAP(x,y) int t ; t=x ; x=y ; y=t;
#define min(x,y) return x<y?x:y;

void BubbleSort(int *num,int len){
    int i,j;
    for(i = len-1 ; i > 0  ; i--){
        for(j = 0 ; j < i ; j++){
            if(num[j] > num[j+1]){
                SWAP(num[j],num[j+1]);
            }
        }
    }
}

void InsertionSort(int *num,int len){
    int i,j;
    for(i = 1 ; i < len ; i++){
        for(j = i ; j > 0 ; j--){
            if(num[j] < num[j-1]){
                SWAP(num[j],num[j-1]);
            }
        }
    }
}

void SelectionSort(int *num,int len){
    int i,j,k;
    int min;
    int index;
    for(i = 0 ; i < len ; i++){
        min = 100000000;
        for(j = i ; j < len ; j++){
            if(num[j] < min){
                min = num[j];
                index = j;
            } 
        }
        for(k = index-1 ; k >= i ; k--){
            num[k+1] = num[k];
        }
        num[i] = min;
    }

}

void MergeSort(int *num,int* reg,int low,int high){
    if(low >= high)
        return;
    int mid = (high+low)/2;
    int start1 = low , end1 = mid;
    int start2 = mid+1 , end2 = high;
    MergeSort(num,reg,low,mid);
    MergeSort(num,reg,mid+1,high);

    int k = low;
    while(start1 <= end1 && start2 <= end2){
        reg[k++] = num[start1] < num[start2]?num[start1++]:num[start2++];
    }
    while(start1 <= end1){
        reg[k++] = num[start1++];
    }
    while(start2 <= end2){
        reg[k++] = num[start2++];
    }
    for(k=low;k<=high;k++){
        num[k] = reg[k];
    }
}

void MergeSort_2(int *num,int len){
    int *reg = (int*) malloc (len*sizeof(int));
    int start,seg;
    int i;
    for(seg=1;seg<len;seg = 2*seg){
        for(start=0 ; start+seg< len; start += (2*seg)){   
            int start1 = start,end1 = start1+seg;
            int start2 = end1, end2 = start2+seg; 
            if(end2 > len) end2 = len;
            int k = start;
            while(start1 < end1 && start2 < end2){
                reg[k++] = num[start1]<num[start2]?num[start1++]:num[start2++];
            }
            while(start1 < end1){
                reg[k++] = num[start1++];   
            }
            while(start2 < end2){
                reg[k++] = num[start2++];
            }

            for(i=start;i<end2;i++){
                num[i] = reg[i];
            }
        }
    }
}


void QuickSort(int *num,int left,int right){
    if(left >= right) return;
    int pivot = num[left];
    int i = left+1;
    int j = right;
    while(1){
        while(i <= right){
            if(num[i] > pivot){
                break;
            }
            i++;
        }

        while(j > left){
            if(num[j] < pivot){
                break;
            }
            j--;
        }

        if(i>j) break;
        SWAP(num[i],num[j]);
    }
    SWAP(num[left],num[j]);
    QuickSort(num,left,j-1);
    QuickSort(num,j+1,right);
}


int main(){
    int a[10] = { -1, 4,5,9,2,55,10,23,1,0 };
    int i;
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    BubbleSort(a,10);
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
