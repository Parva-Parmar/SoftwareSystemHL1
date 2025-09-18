/*
============================================================================
Name : 2.c
Author : Parva Parmar
Description :
Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
============================================================================
*/

#include<stdio.h>

int main() {
    while(1);
    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q2$ gcc loop.c -o loop
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q2$ ./loop &
[1] 10609


dr-xr-xr-x  9 deku             deku                           0 Aug 18 11:06 10609

What /proc shows

Each numbered directory corresponds to a running process, named after its PID.

Inside /proc/<PID>/, you’ll find info about that process (memory maps, command line, environment, open file descriptors, etc.).

For your case:

ls -l /proc/10609


will show detailed files like:

cmdline → command that started it

status → current state (running, sleeping, etc.)

fd/ → file descriptors open by your process

stat → lots of process stats

Next steps you might try

See what the process is doing:

cat /proc/10609/status


Check the command line:

cat /proc/10609/cmdline


Monitor it live:

top -p 10609


If you want to stop it:

kill 10609
*/



/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q2$ ls -l /proc/10609
total 0
-r--r--r--  1 deku deku 0 Aug 18 11:11 arch_status
dr-xr-xr-x  2 deku deku 0 Aug 18 11:11 attr
-rw-r--r--  1 deku deku 0 Aug 18 11:11 autogroup
-r--------  1 deku deku 0 Aug 18 11:11 auxv
-r--r--r--  1 deku deku 0 Aug 18 11:11 cgroup
--w-------  1 deku deku 0 Aug 18 11:11 clear_refs
-r--r--r--  1 deku deku 0 Aug 18 11:06 cmdline
-rw-r--r--  1 deku deku 0 Aug 18 11:11 comm
-rw-r--r--  1 deku deku 0 Aug 18 11:11 coredump_filter
-r--r--r--  1 deku deku 0 Aug 18 11:11 cpu_resctrl_groups
-r--r--r--  1 deku deku 0 Aug 18 11:11 cpuset
lrwxrwxrwx  1 deku deku 0 Aug 18 11:11 cwd -> '/media/deku/Data/Software systems/hands-on-1/Q2'
-r--------  1 deku deku 0 Aug 18 11:11 environ
lrwxrwxrwx  1 deku deku 0 Aug 18 11:11 exe -> '/media/deku/Data/Software systems/hands-on-1/Q2/loop'
dr-x------  2 deku deku 6 Aug 18 11:11 fd
dr-xr-xr-x  2 deku deku 0 Aug 18 11:11 fdinfo
-rw-r--r--  1 deku deku 0 Aug 18 11:11 gid_map
-r--------  1 deku deku 0 Aug 18 11:11 io
-r--------  1 deku deku 0 Aug 18 11:11 ksm_merging_pages
-r--------  1 deku deku 0 Aug 18 11:11 ksm_stat
-r--r--r--  1 deku deku 0 Aug 18 11:11 latency
-r--r--r--  1 deku deku 0 Aug 18 11:11 limits
-rw-r--r--  1 deku deku 0 Aug 18 11:11 loginuid
dr-x------  2 deku deku 0 Aug 18 11:11 map_files
-r--r--r--  1 deku deku 0 Aug 18 11:11 maps
-rw-------  1 deku deku 0 Aug 18 11:11 mem
-r--r--r--  1 deku deku 0 Aug 18 11:11 mountinfo
-r--r--r--  1 deku deku 0 Aug 18 11:11 mounts
-r--------  1 deku deku 0 Aug 18 11:11 mountstats
dr-xr-xr-x 65 deku deku 0 Aug 18 11:11 net
dr-x--x--x  2 deku deku 0 Aug 18 11:11 ns
-r--r--r--  1 deku deku 0 Aug 18 11:11 numa_maps
-rw-r--r--  1 deku deku 0 Aug 18 11:11 oom_adj
-r--r--r--  1 deku deku 0 Aug 18 11:11 oom_score
-rw-r--r--  1 deku deku 0 Aug 18 11:11 oom_score_adj
-r--------  1 deku deku 0 Aug 18 11:11 pagemap
-r--------  1 deku deku 0 Aug 18 11:11 patch_state
-r--------  1 deku deku 0 Aug 18 11:11 personality
-rw-r--r--  1 deku deku 0 Aug 18 11:11 projid_map
lrwxrwxrwx  1 deku deku 0 Aug 18 11:11 root -> /
-rw-r--r--  1 deku deku 0 Aug 18 11:11 sched
-r--r--r--  1 deku deku 0 Aug 18 11:11 schedstat
-r--r--r--  1 deku deku 0 Aug 18 11:11 sessionid
-rw-r--r--  1 deku deku 0 Aug 18 11:11 setgroups
-r--r--r--  1 deku deku 0 Aug 18 11:11 smaps
-r--r--r--  1 deku deku 0 Aug 18 11:11 smaps_rollup
-r--------  1 deku deku 0 Aug 18 11:11 stack
-r--r--r--  1 deku deku 0 Aug 18 11:06 stat
-r--r--r--  1 deku deku 0 Aug 18 11:11 statm
-r--r--r--  1 deku deku 0 Aug 18 11:06 status
-r--------  1 deku deku 0 Aug 18 11:11 syscall
dr-xr-xr-x  3 deku deku 0 Aug 18 11:11 task
-rw-r--r--  1 deku deku 0 Aug 18 11:11 timens_offsets
-r--r--r--  1 deku deku 0 Aug 18 11:11 timers
-rw-rw-rw-  1 deku deku 0 Aug 18 11:11 timerslack_ns
-rw-r--r--  1 deku deku 0 Aug 18 11:11 uid_map
-r--r--r--  1 deku deku 0 Aug 18 11:11 wchan
*/