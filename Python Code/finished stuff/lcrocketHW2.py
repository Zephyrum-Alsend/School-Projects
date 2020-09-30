def build_periodic_table(filename="periodic_table.txt"):
    input_file = open(filename, 'r')
    table = dict()
    for element in input_file:
        tokens = element.split()
        table[tokens[2]] = (tokens[1], int(tokens[0]), float(tokens[3]))
    return table


##########FORMATING##########
def COLUMN_WIDTHS():
    return (5, 20, 5, 20) #Change these numbers to alter column width

def get_format():
    width = COLUMN_WIDTHS()
    return '{0:'+str(width[0])+'} {1:'+str(width[1])+'} {2:'+str(width[2])+'} {3:'+str(width[3])+'}'

def get_width():
    width = COLUMN_WIDTHS()
    w = int()
    for i in width:
        w += i
    return w


##########OPTION1##########
def search_by_symbolname(symbolname, ptable):
    return [(key, ptable[key][0], ptable[key][1], ptable[key][2]) for key in ptable if symbolname.lower() in key.lower() or symbolname.lower() in ptable[key][0].lower()]

def sym_search(ptable):
    results = search_by_symbolname(input('Enter a search term: '), ptable)
    
    print (get_format().format('#','Element name','Sym','Mass'))
    print('=' * get_width())
    for e in results:
        print (get_format().format(str(e[2]), str(e[1]), str(e[0]), str(e[3])))
    print('=' * get_width())
    
    return


##########OPTION2##########
def search_by_atomic_mass(min_mass, max_mass, ptable):
    return [(key, ptable[key][0], ptable[key][1], ptable[key][2]) for key in ptable if min_mass <= ptable[key][2] <= max_mass]

def mass_search(ptable):
    try:
        results = search_by_atomic_mass(float(input('Enter a minimum mass: ')), float(input('Enter a maximum mass: ')), ptable)
        
        print (get_format().format('#','Element name','Sym','Mass'))
        print('=' * get_width())
        for e in results:
            print (get_format().format(str(e[2]), str(e[1]), str(e[0]), str(e[3])))
        print('=' * get_width())
    
    except:
        print('NON-NUMERIC INPUT.')
    
    return


##########OPTION3##########
def molecular_mass_calculation(molecule, ptable):
    mass = 0
    try:
        for x in molecule:
            mass += ptable[x[0]][2] * int(x[1])
    
    except:
        print('INVALID SYNTAX.')
        mass = 0
    
    return mass

def mass_calc(ptable):
    molecule = list()
    
    while True:
        sym = input('Enter atomic symbol of element: ')
        if sym == '.':
            break
       
        sym = sym[0].upper() + sym[1:].lower()
        
        num = input('Enter number of atoms of ' + sym + ' in molecule: ')
        
        molecule.append((sym, num))
    
    mass = molecular_mass_calculation(molecule, ptable)
    
    if mass != 0:
        print('The molecular mass is ' + str(mass))


##########MAIN##########
try:
    ptable = build_periodic_table()
    print('Loaded Periodic Table!')
    userInput = 0
except:
    print('Unable to find Periodic Table...')
    userInput = 4

while userInput != '4':
    userInput = input('\n1) Search by symbol/name' +
                      '\n2) Search by atomic mass' +
                      '\n3) Molecular Mass Calculation' +
                      '\n4) Quit\n' +
                      '\nPlease enter your choice: ')
    
    if '1' in userInput:
        sym_search(ptable)
    elif '2' in userInput:
        mass_search(ptable)
    elif '3' in userInput:
        mass_calc(ptable)
##########END##########