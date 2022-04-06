class overflow_bucket():
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.next = None


class Table():
    def __init__(self, size):
        self.size = size
        self.table_arr = self.__create_arr__()

    def __create_arr__(self):
        arr = []
        for i in range(0, self.size):
            arr.append(overflow_bucket(None, None))
        return arr

    def __hash_func__(self, key):
        ind = 0
        cur_sym = 0
        for i in key:
            ind += ord(i)
            cur_sym += 1
        return ind % self.size

    def __solve_collision__(self, key, elem):
        hash = self.__hash_func__(key)
        place_of_coll = self.table_arr[hash]
        while place_of_coll.next is not None:
            place_of_coll = place_of_coll.next
        place_of_coll.next = elem

    def __create_new_tabl_elem__(self, key, val):
        new_elem = overflow_bucket(key, val)
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
        hash = self.__hash_func__(key)
        search_elem = self.table_arr[hash]
        while search_elem.key != key and search_elem.next is not None:
            search_elem = search_elem.next
        search_arr.append(search_elem)
        return search_arr

    def delete(self, key):
        hash = self.__hash_func__(key)
        place_to_del = self.table_arr[hash]
        prev_to_del = overflow_bucket(None, None)
        while place_to_del.next is not None and place_to_del.key != key:
            prev_to_del = place_to_del
            place_to_del = place_to_del.next

        self.table_arr[hash] = prev_to_del
        self.table_arr[hash].next = place_to_del.next
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

