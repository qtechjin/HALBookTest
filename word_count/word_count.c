#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/miscdevice.h>
#include<asm/uaccess.h>

#define MODULE_NAME "wordcount"
static struct file_operations dev_fops=
{ .owner = THIS_MODULE };
//the information of device
//minor:
static struct miscdevice misc=
{
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEVICE_NAME,
    .fops = &dev_fops
};

static int word_count_init(void)
{
    int ret;
	ret = misc_register(&misc);
	//output log
    printk("word_count_init_sucess\n");
    return ret;
}
static void word_count_exit(void)
{
	misc_deregister(&misc);
    printk("word_count_exit_sucess\n");
}




module_init(word_count_init);
module_exit(word_count_exit);
MODULE_AUTHOR("ustcjin");
MODULE_LICENSE("GPL");
