#include <stdint.h>

extern void load_page_directory(uint32_t addr);

// Create a blank page directory.
// TODO: Write a page frame allocator
uint32_t page_directory[1024] __attribute__((aligned(4096)));

// Also, create a blank page table.
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

static void setup_page_directory()
{
    // Initialize the page directory. Set everything to empty.
    //set each entry to not present
    int i;
    for (i = 0; i < 1024; i++)
    {
        // This sets the following flags to the pages:
        //   Supervisor: Only kernel-mode can access them
        //   Write Enabled: It can be both read from and written to
        //   Not Present: The page table is not present
        page_directory[i] = 0x00000002;
    }
}

static void setup_page_table()
{

    // holds the physical address where we want to start mapping these pages to.
    // in this case, we want to map these pages to the very beginning of memory.
    unsigned int i;

    //we will fill all 1024 entries in the table, mapping 4 megabytes
    for (i = 0; i < 1024; i++)
    {
        // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }
}

void create_page_directory()
{
    setup_page_directory();
    setup_page_table();
    // Put the table in the directory.
    // attributes: supervisor level, read/write, present
    page_directory[0] = ((unsigned int)first_page_table) | 3;

    // Lastly, load the directory.
    load_page_directory((uint32_t)&page_directory);
}