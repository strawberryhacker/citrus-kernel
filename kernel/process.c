/// Copyright (C) strawberryhacker

#include <citrus/types.h>
#include <citrus/thread.h>
#include <citrus/page_alloc.h>
#include <citrus/mm.h>
#include <citrus/kmalloc.h>
#include <citrus/align.h>
#include <citrus/list.h>
#include <citrus/page_alloc.h>
#include <citrus/pt_entry.h>
#include <citrus/mem.h>
#include <citrus/panic.h>
#include <citrus/cache.h>

/// This sets up the new process memory space and 
struct page* process_mm_init(struct thread* thread, u32 stack_size)
{
    // The init process has to dynamically allocte the mm struct
    struct thread_mm* mm = (struct thread_mm *)
        kzmalloc(sizeof(struct thread_mm));

    mm_process_init(mm);
    thread->mm = mm;

    // Make the main level 1 page table
    struct page* lv1 = lv1_pt_alloc();
    mm_process_add_page(lv1, mm);
    mm->ttbr_phys = page_to_pa(lv1);

    return NULL;
}
