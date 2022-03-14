#include <iostream>
#include <ctime>
using namespace std;

class My_own_arr{
    private:
        int len;
        int* arr;
        int cur_ind;
        bool sorted = false;

        void set_len(int new_len){
            len = new_len;
        }

    public:

        My_own_arr(int lenght){
            set_len(lenght);
            arr = new int[len];
            cur_ind = 0;
        }

        void append(int a){
            if(cur_ind <= len){
                arr[cur_ind] = a;
                cur_ind++;
            }
            else{
                cout << "Your array size is " << len << " what you gonna do with number " << a << endl;
                throw EOF;
            }
        }

        void print_array(){
            for(int i = 0; i < len; i++){
                cout << arr[i] << endl;
            }
            cout << endl;
        }


        void create_and_fill_arr(int size){
            set_len(size);
            srand(time(0));
            arr = new int[len];
            for (int count = 0; count < len; count++)
                arr[count] = (rand() + 1) / float((rand() % 10 + 1));
        }

        bool search(int num){
            for(int i = 0; i<len; i++){
                if (arr[i] == num){
                    return true;
                }
            }
            return false;
        }

        void swap_by_val(int a, int b){
            int num1, num1_ind;
            int num2, num2_ind;

            int i = 0;

            while(arr[i] != a && arr[i]!=b){
                i++;
            }

            num1 = arr[i];
            num1_ind = i;
            i++;

            while(arr[i] != a && arr[i]!=b){
                i++;
            }

            num2 = arr[i];
            num2_ind = i;

            arr[num1_ind] = num2;
            arr[num2_ind] = num1;

        }

        void paste_to(int index, int element)
        {
            if (index > len){
                return;
            }

            int* new_arr = new int[len + 1];

            for (int i = 0; i < index; i++)
                new_arr[i] = arr[i];
            new_arr[index] = element;

            for (int i = index + 1; i < len + 1; i++)
                new_arr[i] = arr[i - 1];

            set_len(len+1);
            delete[] arr;
            arr = new_arr;
        }


        void delete_from(int index){
            if (index >= len){
                return;
            }

            int* new_arr = new int[len - 1];
            int new_arr_i = 0;
            int old_arr_i = 0;

            while (new_arr_i<len){
                if (old_arr_i == index){
                    old_arr_i++;
                    continue;
                }
                new_arr[new_arr_i] = arr[old_arr_i];
                old_arr_i++;
                new_arr_i++;
            }

            set_len(len-1);

            delete[] arr;
            arr = new_arr;
        }


        void shake_sort(){
            if(len <= 1){
                return;
            }

            sorted = true;

            bool is_sort = true;
            int* begin = &arr[0-1];
            int* end = &arr[len-1];


            while (is_sort){
                is_sort = false;
                begin++;
                for(int* i = begin; i < end; i++){
                    if (*i > *(i + 1)) {
                        swap(*i, *(i + 1));
                        is_sort = true;
                    }
                }
                if (!is_sort) break;
                end--;
                for (int* i = end; i > begin; i--) {
                    if (*i < *(i - 1)) {
                        swap(*i, *(i - 1));
                        is_sort = true;
                    }
                }
            }
        }


        bool bin_search(int num){

            if(!sorted){
                return false;
            }

            int start = 0;
            int end = len;
            int border = (start+end)/2;
            bool find = false;

            while (!find){
                if(arr[border] == num){
                    find = !find;
                }
                else if (start == end){
                    break;
                }
                else if(arr[border] < num){
                    start = border;
                }
                else if(arr[border] > num){
                    end = border;
                }
                border = (start+end)/2;
            }
            return  find;
        }


        void delete_from_sort(int element){
            if (element > arr[len-1] && !sorted){
                return;
            }

            int* new_arr = new int[len - 1];
            int new_arr_i = 0;
            int old_arr_i = 0;

            while (new_arr_i != len-1){
                if (arr[old_arr_i] == element){
                    old_arr_i++;
                    continue;
                }
                new_arr[new_arr_i] = arr[old_arr_i];
                old_arr_i++;
                new_arr_i++;
            }

            set_len(len-1);
            delete[] arr;
            arr = new_arr;
        }


        void paste_to_sort(int element)
        {
            if(!sorted){
                return;
            }

            int* new_arr = new int[len + 1];
            int i = 0;

            while(arr[i] <= element && i<len){
                new_arr[i] = arr[i];
                i++;
            }

            new_arr[i] = element;
            i++;

            while(i<len+1){
                new_arr[i] = arr[i-1];
                i++;
            }

            set_len(len+1);
            delete[] arr;
            arr = new_arr;
        }


};






