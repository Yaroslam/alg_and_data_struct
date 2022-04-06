class bucket():
    def __init__(self, key, val):
        self.val = val
        self.key = key


class Table():
    def __init__(self, size):
        self.size = size
        self.table_arr = self.__create_arr__()

    def __create_arr__(self):
        arr = []
        for i in range(0, self.size):
            arr.append(bucket(None, None))
        return arr

    def __hash_func__(self, key):
        ind = 0
        bit_arr = []
        for i in key:
            bit_arr.append(ord(i))

        for i in bit_arr:
            ind = ind ^ i

        return ind

    def __solve_collision__(self, key, elem):
        hash = self.__hash_func__(key)
        step = 0
        place_of_coll = self.table_arr[hash]
        while place_of_coll.val is not None:
            hash = hash + step*step
            try:
                place_of_coll = self.table_arr[hash]
            except IndexError:
                place_of_coll = self.table_arr[hash % self.size]
                step = 1
            step+=1
        self.table_arr[hash] = elem

    def __create_new_tabl_elem__(self, key, val):
        new_elem = bucket(key, val)
        return new_elem

    def insert_val(self, key, val):
        hash = self.__hash_func__(key)
        if self.table_arr[hash].val is not None:
            new_elem = self.__create_new_tabl_elem__(key, val)
            self.__solve_collision__(key, new_elem)
        else:
            self.table_arr[hash].val = val
            self.table_arr[hash].key = key

    def search(self, key):
        search_arr = []
        step = 1
        hash = self.__hash_func__(key)
        search_elem = self.table_arr[hash]

        if(search_elem.val == None):
            search_arr.append(search_elem)
            return search_arr

        while search_elem.key != key:
            hash = hash + step*step
            try:
                search_elem = self.table_arr[hash]
            except IndexError:
                search_elem = self.table_arr[hash % self.size]
                step = 0
            step+=1
        search_arr.append(search_elem)
        return search_arr

    def delete(self, key):
        hash = self.__hash_func__(key)
        step = 1
        place_to_del = self.table_arr[hash]
        while place_to_del.key != key:
            hash = hash+step*step
            place_to_del = self.table_arr[hash]

        self.table_arr[hash] = bucket(None, None)
        return 0

    def print_table(self, keys):
        for i in keys:
            print_arr = self.search(i)
            for i in print_arr:
                print(f"key: {i.key}  val: {i.val}")


def main():
    hs_table = Table(50000)
    hs_table.insert_val("1", "first address")
    hs_table.insert_val("2", "sec address")
    hs_table.insert_val("Hel", "third address")
    hs_table.insert_val("Cau", "fourth address")

    hs_table.print_table(["1", "2", "Hel", "Cau"])
    hs_table.delete("1")
    hs_table.print_table(["1", "2", "Hel", "Cau"])


main()
