# First Report Unix Development

## Hello World in C

```c
#include <stdio.h>

int main()
{
  printf("Hello, World C!\n");
  return 0;
}
```

## Hello World in C++

```cpp
#include <iostream>

int main()
{
  std::cout << "Hello, World C++!" << std::endl;
  return 0;
}
```

## File System in Fedora

Fedora uses the **ext4** file system by default. The ext4 file system is an
enhanced version of ext3, offering features such as:

- **Larger file and file system sizes:** Ext4 supports larger file and file
  system sizes compared to ext3.

- **Improved space management:** Ext4 employs techniques like block allocation
  and space reservation to enhance disk space management.

- **Better performance:** Ext4 provides better performance in terms of read and
  write speeds compared to ext3.

- **Security features:** Ext4 includes features like file integrity checking and
  encryption, enhancing data security within the file system.

## Disk Partitions in Fedora

The partition setup in Fedora can vary, but a typical configuration includes the
following partitions:

1. **Root Partition (/):** This is the main system partition mounted at `/`. It
   contains the operating system files and installed programs.

2. **Boot Partition (/boot):** The `/boot` partition contains boot loader files
   and kernel images necessary for the system to boot. It is often a separate
   partition for better system management and security.

3. **Swap Partition:** Fedora typically has a swap partition used as virtual
   memory when the RAM is full. This partition does not have a specific mount
   point.

4. **User Data Partition (/home):** In some setups, a separate partition is
   configured for the `/home` directory. This partition holds user data such as
   documents, images, and personal configurations.
