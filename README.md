





# **Fillit**

### **Description**

Fillit is an algorithm exercise. 
It's a programm that receives a set of tetraminos and gives you the smallest square possible in which all pieces can fit.
You can find the subject [here](./fillit.en.pdf)

### **Vuilding**

To build:

```bash
$ make
```
### **Testing**

To test, we have to generate random tetraminos, using tetragen:

```bash
$ ./tetrigen [option 1] [option 2] [number]
```

Example:

```bash
$ ./tetrigen -v -f 13
```
The output of this example will be a valid file of 13 tetriminos saved in **test.fillit**.

Then :

```bash
$ ./fillit test.fillit
```

### **Options of tetragen**

**[options #1]**
+ -v: valid map
+ -i: invalid map

**[options #2]**
+ -f: write the map in a file (test.fillit)
+ -s: send the map directly to the stdin

**[number]**
+ Select between 1 and 26 tetriminos per file.

### **Credits for tetragen**

+ [hqro](https://github.com/hqro)
