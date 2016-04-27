# Red-Black-Trees

######P2.1	Ιδιότητες των Red – Black Trees
Τα red – black trees είναι ένα μοντέλο δυαδικών δένδρων αναζήτησης (binary search trees), όπου κάθε κόμβος τους, πέρα από τα πεδία κλειδί, αριστερό_παιδί, δεξιό_παιδί και πατέρας, περιέχει μία επιπλέον πληροφορία που τον περιγράφει· το χρώμα. Το χρώμα ενός κόμβου μπορεί να είναι είτε μαύρο είτε κόκκινο· εξ ου και το όνομα της δομής. Η τιμή χρώματος που θα έχουν οι κόμβοι ενός red – black tree, καθορίζεται με βάση τις ιδιότητες του δένδρου, οι οποίες θα πρέπει να ικανοποιούνται κάθε φορά:

1.	Κάθε κόμβος είναι είτε κόκκινος είτε μαύρος
2.	Ο ριζικός κόμβος είναι πάντα μαύρος
3.	Κάθε καταληκτικός κόμβος (NIL) έχει μαύρο χρώμα
4.	Ένας κόκκινος κόμβος έχει και τα δύο παιδιά του μαύρα
5. Όλες οι καθοδικές διαδρομές, από έναν κόμβο προς καταληκτικούς κόμβους, περιέχουν ισάριθμους μαύρους κόμβους

Οι παραπάνω ιδιότητες αποτελούν τους περιορισμούς που διέπουν το χρωματισμό των κόμβων σε ένα red – black tree. Η τήρησή τους εγγυάται ότι καμία διαδρομή, μεταξύ της ρίζας και ενός καταληκτικού κόμβου, δεν θα έχει μήκος μεγαλύτερο από το διπλάσιο, οποιασδήποτε άλλης διαδρομής. Η συνθήκη αυτή, κατά προσέγγιση,  καθιστά τα red – black trees ισοσταθμισμένα.
Με βάση την τελευταία συνθήκη, προκύπτει ότι το ύψος οποιουδήποτε red – black tree με n εσωτερικούς κόμβους, δίνεται από τη σχέση h = 2log(n+1). Συνεπώς, ένα οποιοδήποτε red – black tree  με n εσωτερικούς κόμβους, αποτελεί ένα δυαδικό δέντρο αναζήτησης με ύψος O(log n). Εύκολα λοιπόν, κανείς συμπεραίνει ότι σε δομές red – black trees, οι πράξεις δυναμικών συνόλων υλοποιούνται σε χρόνο O(log n).

######P2.2	Περιστροφές (Rotations)
Πράξεις δυναμικών συνόλων, όπως οι ΕΙΣΑΓΩΓΗ και ΔΙΑΓΡΑΦΗ, μπορούν να τροποποιήσουν τη δομή ενός δέντρου, με αποτέλεσμα να χαθούν οι ιδιότητες των red – black trees. Για το λόγο αυτό, τα red – black trees διαθέτουν ειδικό μηχανισμό που αποκαθιστά τη δομή τους. Οι περιστροφές είναι μία τοπική πράξη (εκτελείται σε ένα δένδρο αναζήτησης), η οποία διατηρεί την ιδιότητα του δυαδικού δένδρου αναζήτησης (binary search tree). Τα red – black trees εκτελούν αριστερές και δεξιές περιστροφές μεταξύ ενός κόμβου και του δεξιού/αριστερού θυγατρικού του, αντίστοιχα. Όπως φαίνεται και στο παρακάτω σχήμα, η εκτέλεση μίας δεξιάς περιστροφής καθιστά τον αριστερό θυγατρικό κόμβο x τη νέα ρίζα του υποδένδρου, μετατρέποντας τον πατρικό y σε δεξιό_παιδί του x. Η εκτέλεση μίας αριστερής περιστροφής είναι συμμετρική και επιφέρει τα αντίστροφα αποτελέσματα.

(picture here)
Figure 1 Οι πράξεις περιστροφής σε ένα δυαδικό δένδρο αναζήτησης

Βασική προϋπόθεση για την εκτέλεση των περιστροφών είναι ο πατρικός κόμβος της ρίζας (root) να είναι ο NIL, ενώ ο εκάστοτε θυγατρικός που συμμετέχει στην περιστροφή να μην είναι ο NIL. Παρακάτω παρουσιάζονται οι κώδικες της δεξιάς και της αριστερής περιστροφής.

Κατά την εκτέλεση των συναρτήσεων right_rotation() και left_rotation(), μεταβάλλονται μόνο οι δείκτες parent, right_child και left_child των κόμβων, που συμμετέχουν στην περιστροφή. Τα υπόλοιπα πεδία τους, καθώς κι οι υπόλοιποι κόμβοι, παραμένουν αμετάβλητα. Η εκτέλεση μίας περιστροφής ολοκληρώνεται σε χρόνο Ο(1).
Οι μηχανισμοί των περιστροφών επιτρέπουν στα red – black trees να διατηρούνται ισοσταθμισμένα καθ’ όλη τη διάρκεια, και κατά συνέπεια, ο χρόνος εκτέλεσης των πράξεων ΕΙΣΑΓΩΓΗ και ΔΙΑΓΡΑΦΗ, να παραμένει O(log n).

######P2.3	Εισαγωγή (Insert)
Καθώς τα red – black trees είναι δυαδικά δένδρα αναζήτησης, εφοδιασμένα με κάποιες επιπλέον ιδιότητες, η ΕΙΣΑΓΩΓΗ δεν μπορεί να διαφέρει αρκετά από την αντίστοιχη πράξη σε ένα κοινό δυαδικό δένδρο αναζήτησης. Οι βασικές διαφορές αφορούν τη διατήρηση των παραπάνω ιδιοτήτων. Αρχικά, ο νέος κόμβος που εισάγεται στη δομή χρωματίζεται κόκκινος, ενώ οι δείκτες αριστερό_παιδί και δεξιό_παιδί δείχνουν στον κόμβο NIL. Επιπλέον, όπως έχει ήδη αναφερθεί, οι ιδιότητες ενός red – black tree μπορεί να χαθούν μετά την εκτέλεση μίας πράξης δυναμικού συνόλου. Για την αποκατάσταση των ιδιοτήτων αυτών, μόλις ολοκληρωθεί η ΕΙΣΑΓΩΓΗ, καλείται η βοηθητική συνάρτηση insert_fix_up(), που αναλαμβάνει αυτή τη διαδικασία.

Εάν το δέντρο είναι κενό, τότε ο νεοεισαχθείς κόμβος καταλαμβάνει θέση ρίζας στο δένδρο και αυτομάτως παραβιάζει την ιδιότητα 2. Η τελευταία γραμμή κώδικα της insert_fix_up() αποκαθιστά αυτού του είδους παραβιάσεις, όποτε και αν εμφανιστούν. Σε αντίθετη περίπτωση, όπου η δομή δεν είναι κενή, ο νεοεισαχθείς κόκκινος κόμβος αποκτά δύο μαύρα παιδιά NIL και ένα πατέρα χρώματος είτε μαύρου, είτε κόκκινου. Εάν ο πατέρας του νέου κόμβου είναι μαύρος, τότε όλες οι ιδιότητες διατηρούνται, χωρίς η εισαγωγή του νέου κόμβου να δημιουργεί κάποια παραβίαση. Αντίθετα, αν ο πατέρας είναι και αυτός κόκκινος, τότε άμεσα παραβιάζεται η 4η ιδιότητα των red – black trees, η οποία θέλει και τα δύο παιδιά ενός κόκκινου κόμβου να είναι μαύρα. Συνολικά, οι περιπτώσεις στις οποίες ένας κόκκινος κόμβος αποκτά ένα επίσης κόκκινο παιδί είναι έξι. Ωστόσο, ανά δύο, οι περιπτώσεις αυτές είναι απολύτως συμμετρικές μεταξύ τους. Η συμμετρία βρίσκεται ανάμεσα στα δύο υποδένδρα του «παππού» του (αριστερό/δεξιό). Παρακάτω αναλύονται οι τρεις περιπτώσεις που προκύπτουν όταν ο νέος κόμβος τοποθετείται στο αριστερό υποδένδρο του «παππού» του.
	Περίπτωση 1: Ο «θείος» του νέου κόμβου είναι κόκκινος
Στη κατάσταση αυτή, τόσο ο πατέρας του νέου κόμβου, όσο και ο αδελφός αυτού (που είναι «θείος» του νέου κόμβου), είναι και οι δύο κόκκινοι. Μέχρι πριν την εισαγωγή, όλες οι ιδιότητες τηρούνταν. Δεδομένης της τήρησης λοιπόν, ο «παππούς» του νέου κόμβου (new_node->parent->parent) θα πρέπει να είναι μαύρος. Η τελευταία συνθήκη, μας προτρέπει να χρωματίσουμε τον πατέρα και το «θείο» μαύρους. Με αυτό τον τρόπο, το πρόβλημα του κοινού κόκκινου χρώματος επιλύεται μεταξύ του νέου κόμβου και του πατρικού του. Ωστόσο, η ιδιότητα 5, επιβάλλει να χρωματίσουμε τον «παππού» κόκκινο, ώστε να μη μεταβληθεί το πλήθος των μαύρων κόμβων που περιέχονται κατά μήκος μίας διαδρομής προς αυτούς. Πλέον, ο έλεγχος μεταφέρεται στον «παππού», δύο επίπεδα προς τα πάνω, καθώς το κόκκινο χρώμα του, ενδεχομένως να παραβιάζει εκ νέου την ιδιότητα 4 μεταξύ αυτού και του πατρικού του κόμβου.
 Figure 2 Η περίπτωση 1 της insert_fix_up(). Η εισαγωγή του νέου κόμβου Α παραβιάζει την ιδιότητα 4. Η δράση της insert_fix_up() μεταβάλλει το χρώμα των κόμβων B, C και D. Πλέον, η ιδιότητα 4 μπορεί να παραβιάζεται μόνο από τον κόμβο C και τον πατρικό του.
	Περίπτωση 2: Ο «θείος» του νέου κόμβου είναι μαύρος και ο νέος κόμβος είναι δεξί_παιδί
	Περίπτωση 3: Ο «θείος» του νέου κόμβου είναι μαύρος και ο νέος κόμβος είναι αριστερό_παιδί
Στις περιπτώσεις 2 και 3, το πρόβλημα του κοινού κόκκινου χρώματος μεταξύ του νέου κόμβου και του πατρικού του εμφανίζεται και πάλι. Αντίθετα από την περίπτωση 1 όμως, αυτή τη φορά ο «θείος» είναι μαύρος. Η διαφορά μεταξύ των δύο αυτών περιπτώσεων εντοπίζεται στη σχέση μεταξύ του νέου κόμβου και του πατέρα του. Στην περίπτωση 2, ο νέος κόμβος είναι δεξιό_παιδί του πατρικού του. Ωστόσο, με την εκτέλεση μίας αριστερής περιστροφής (left_rotate()), ο νέος κόμβος γίνεται πατρικός του πατέρα του και αντίστροφα, ο πατρικός γίνεται αριστερό_παιδί του νέου κόμβου, όπως φαίνεται και στο παρακάτω σχήμα. Επειδή και οι δύο κόμβοι είναι κόκκινοι, καμία από τις υπόλοιπες ιδιότητες δε μεταβάλλεται, η ιδιότητα 4 εξακολουθεί να παραβιάζεται, ενώ η νέα τοπολογία περιγράφεται από την περίπτωση 3.
 
Figure 3 Οι περιπτώσεις 2 και 3 της insert_fix_up()  όταν ο νέος κόμβος τοποθετείται στο αριστερό υποδένδρο του «παππού». Η εισαγωγή του νέου κόμβου (Α και Β αντίστοιχα) παραβιάζει την ιδιότητα 4. Με την εκτέλεση μίας αριστερή περιστροφής, η περίπτωση 2 ανάγεται στην περίπτωση 3. Στη περίπτωση 3, η δράση της insert_fix_up() μεταβάλλει το χρώμα των κόμβων Α και C και εκτελεί μία δεξιά περιστροφή.
Στην περίπτωση 3, ανεξάρτητα από τη προέλευση του κόμβου Β στη θέση αυτή (είτε μέσω της περίπτωσης 2, είτε απευθείας από εισαγωγή), ο «θείος» του παραμένει μαύρος. Επιπλέον, ο «παππούς» παραμένει επίσης μαύρος, αφού ούτε η περίπτωση 2, ούτε η εισαγωγή νέου κόμβου τον επηρεάζουν. Σε αυτή τη φάση της αποκατάστασης, το πρόβλημα του κοινού κόκκινου χρώματος επιλύεται, αρχικά, με τον αναχρωματισμό του πατέρα και του «παππού» του Β. Για να μη διαταραχθεί η ιδιότητα 5, η διαδικασία ολοκληρώνεται με την εφαρμογή μίας δεξιάς περιστροφής (right_rotate()) στον πατρικό κόμβο του Β. Πλέον, στο δένδρο δεν μπορεί να υπάρχει κανένα ζεύγος διαδοχικών κόκκινων κόμβων και η εκτέλεση του βρόγχου while τερματίζει.
Η συνάρτηση insert() απαιτεί χρόνο Ο(log n) μέχρι να ενσωματώσει το νέο κόμβο στη δομή. Η αποκατάσταση των ιδιοτήτων που παραβιάζονται γίνεται από την insert_fix_up() και διαρκεί για όσο χρόνο εκτελείται η while. Κατά την αποκατάσταση, δεν εκτελούνται ποτέ περισσότερες από δύο περιστροφές καθώς, όταν εκτελεστούν οι περιπτώσεις 2 ή/και 3, ο βρόγχος τερματίζεται. Ωστόσο, η επανάληψη του βρόγχου οφείλεται στην περίπτωση 1. Κατά την εκτέλεσή της, το πρόβλημα του κοινού κόκκινου χρώματος επιλύεται και ο έλεγχος μεταφέρεται δύο επίπεδα προς τα πάνω, προκαλώντας το βρόγχο να εκτελεστεί Ο(log n) φορές. Τελικά ο συνολικός χρόνος που απαιτείται για την εκτέλεση της insert() είναι Ο(log n), αποτέλεσμα αναμενόμενο, αφού όπως έχουμε ήδη αναφέρει τα red – black trees είναι δυαδικά δένδρα αναζήτησης με ύψος Ο(log n).

######P2.4	Διαγραφή (Delete)
Όπως η ΕΙΣΑΓΩΓΗ, έτσι και η ΔΙΑΓΡΑΦΗ δεν διαφέρει αρκετά από την αντίστοιχη πράξη σε ένα κοινό δυαδικό δέντρο. Οι όποιες διαφορές οφείλονται και πάλι στις ιδιότητες που πρέπει να τηρούνται. Αρχικά, εντοπίζεται ο διαγραφόμενος κόμβος και ανάλογα με τους απογόνους του, αποφασίζεται ποιος κόμβος θα τον διαδεχθεί. Εάν ο διαγραφόμενος κόμβος έχει κόκκινο χρώμα, οι ιδιότητες των red – black trees εξακολουθούν να ισχύουν. 

Αντίθετα, αν ο διαγραφόμενος κόμβος είναι μαύρος, τότε όλοι οι πρόγονοι του κόμβου που διαγράφηκε παραβιάζουν την ιδιότητα 5 καθώς, όλες οι διαδρομές που τον περιλάμβαναν πριν διαγραφεί, τώρα θα έχουν ένα μαύρο κόμβο λιγότερο. Επιπλέον, υπάρχει πιθανότητα να έχουν παραβιασθεί οι ιδιότητες 2, αν διαγραφεί ο ριζικός κόμβος και τη θέση του πάρει ένας κόκκινος κόμβος, και η 4, εάν το θυγατρικός και ο πατρικός του διαγραφέντα κόμβου είναι και οι δύο κόκκινοι. Η αποκατάσταση των ιδιοτήτων των red – black trees γίνεται με την κλήση της συνάρτησης delete_fix_up() πριν την ολοκλήρωση της διαγραφής.
Για την αποκατάσταση της ιδιότητας 5 χρησιμοποιούμε το εξής τέχνασμα.  Αρχικά, ορίζουμε ένα δείκτη x_aux ο οποίος δείχνει σε ένα από τα παιδιά του κόμβου που διαγράφουμε και θεωρούμε ότι μετά τη διαγραφή, ο δείκτης αυτός αποκτά «μαύρο χαρακτήρα», εξαιτίας του κόμβου που διεγράφη. Ο «μαύρος χαρακτήρας» του δείκτη μεταβιβάζεται στον κόμβο που δείχνει κάθε φορά και συνεισφέρει κατά μία μονάδα επιπλέον στο πλήθος των μαύρων κόμβων των διαδρομών που τον περιέχουν. Με αυτό τον τρόπο, ουσιαστικά αποκαθίσταται η ιδιότητα 5, ωστόσο η παραβίαση μεταφέρεται στην ιδιότητα 1. Το χρώμα του κόμβου που δείχνει ο x_aux, πλέον δεν είναι ούτε μαύρο ούτε κόκκινο· επηρεάζεται από το «μαύρο χαρακτήρα» του δείκτη και ο κόμβος γίνεται είτε κοκκινόμαυρος, είτε διπλά μαύρος.
Κατά την εκτέλεση της delete_fix_up() γίνεται αποκατάσταση των ιδιοτήτων 1, 2 και 4.  Η εκτέλεση του βρόγχου while μετατοπίζει τον πρόσθετο «μαύρο χαρακτήρα» προς τα επάνω μέχρι:
1.	ο δείκτης να δείχνει σε έναν κοκκινόμαυρο κόμβο, όπου απλά τον χρωματίζει μαύρο
2.	ο δείκτης να δείχνει στο ριζικό κόμβο, όπου απλώς αφαιρεί τον επιπλέον «μαύρο χαρακτήρα»
3.	να μπορούν να εκτελεστούν κατάλληλες περιστροφές και αναχρωματισμοί
Στο εσωτερικό του βρόγχου εξετάζεται ο κόμβος που δείχνει ο x_aux σε σχέση με τον «αδελφό» του και τα παιδιά του τελευταίου. Οι περιπτώσεις είναι και πάλι συμμετρικές, ανάλογα με το αν ο x_aux δείχνει σε αριστερό ή δεξιό παιδί. Παρακάτω αναλύονται οι διαφορετικές περιπτώσεις που προκύπτουν όταν ο εξεταζόμενος κόμβος είναι αριστερό_παιδί.
	Περίπτωση 1: Ο «αδελφός» του εξεταζόμενου κόμβου είναι κόκκινος
Το γεγονός ότι ο αδελφικός κόμβος είναι κόκκινος συνεπάγεται ότι και τα δύο παιδιά του πρέπει να είναι μαύρα. Χωρίς να παραβιάσουμε καμία ιδιότητα, μπορούμε αρχικά να αλλάξουμε το χρώμα του αδελφικού και του πατρικού κόμβου. Στη συνέχεια, εκτελώντας μία περιστροφή, ο νέος αδελφικός κόμβος θα είναι ένα από τα παιδιά του προηγούμενου αδελφού, η περίπτωση 1 ανάγεται σε μία από τις περιπτώσεις 2, 3 ή 4.
Οι περιπτώσεις 2, 3 και 4 προκύπτουν όταν ο «αδελφός» του εξεταζόμενου κόμβου είναι μαύρος. Η διαφορές τους εντοπίζονται στο χρώμα των θυγατρικών του «αδελφού».
 
Figure 4 Οι περιπτώσεις της delete_fix_up() όταν ο x_aux δείχνει σε αριστερό παιδί. Εδώ, πριν την εκτέλεση της κάθε περίπτωσης, ο x_aux δείχνει τον κόμβο Α
	Περίπτωση 2: Ο «αδελφός» του εξεταζόμενου κόμβου είναι μαύρος, και οι δύο θυγατρικοί κόμβοι του «αδελφού» είναι επίσης μαύροι
Στην περίπτωση αυτή χρωματίζουμε τον αδελφικό κόμβο κόκκινο και μεταφέρουμε το μελανό χαρακτήρα του δείκτη ένα επίπεδο προς τα πάνω, στον πατρικό κόμβο. Ουσιαστικά, αφαιρούμε και από τους δύο κόμβους ένα μελανό χαρακτήρα, αφήνοντας στον εξεταζόμενο κόμβο το χρώμα που είχε πριν πάρει τον επιπλέον «μαύρο χαρακτήρα». Ο πατρικός κόμβος τώρα θα είναι είτε κοκκινόμαυρος, είτε διπλά μαύρος και ο βρόγχος εκτελείται, εξετάζοντας πλέον τον πατρικό κόμβο. Εάν η μετάβαση του ελέγχου έχει γίνει από την περίπτωση 1, τότε ο εξεταζόμενος κόμβος, πριν μελετηθεί στην περίπτωση 2, χρωματίζεται κόκκινος. Στην περίπτωση αυτή, η συνθήκη ελέγχου του βρόγχου δεν ικανοποιείται και ο βρόγχος τερματίζει. Πριν τον τερματισμό της διαδικασίας, ο εξεταζόμενος κόμβος στον οποίο δείχνει ο x_aux χρωματίζεται μαύρος, ικανοποιώντας την ιδιότητα 4.
	Περίπτωση 3: Ο «αδελφός» του εξεταζόμενου κόμβου είναι μαύρος, το αριστερό_παιδί του  «αδελφού» είναι κόκκινο, ενώ το δεξιό_παιδί του είναι κόκκινο
Στην κατάσταση αυτή, αρχικά αλλάζουμε το χρώμα των κόμβων «αδελφός» και αριστερό_παιδί (του «αδελφού») και στη συνέχεια εκτελούμε μία δεξιά περιστροφή στον «αδελφό». Καμία επιπλέον από τις ιδιότητες δεν παραβιάζεται κατά τη διάρκεια της παραπάνω διαδικασίας, ενώ ταυτόχρονα, ο αριστερό_παιδί του «αδελφού» γίνεται ο νέος «αδελφός» του εξεταζόμενου κόμβου και είναι μαύρος. Ο πρώην «αδελφός», και πρώην πατέρας του νέου «αδελφού», πλέον έχει γίνει αριστερό_παιδί του νέου «αδελφού» και είναι κόκκινος. Η νέα διάταξη παραπέμπει στην περίπτωση 4.
	Περίπτωση 4: Ο «αδελφός» του εξεταζόμενου κόμβου είναι μαύρος και το δεξιό_παιδί του είναι κόκκινο
Στην παρούσα φάση, αφού αναχρωματίσουμε τον πατέρα του εξεταζόμενου κόμβου, τον «αδελφό» του, αλλά και το δεξιό_παιδί του, εκτελείται μία αριστερή περιστροφή στον πατέρα. Η διαδικασία δε μεταβάλλει καμία από τις ισχύουσες ιδιότητες της δομής, ενώ ταυτόχρονα εξαλείφει τον πρόσθετο μαύρο χαρακτήρα από τον εξεταζόμενο κόμβο, μεταφέροντάς τον στη ρίζα του red – black tree, ώστε να ικανοποιηθεί η ιδιότητα 2. Καθώς η συνθήκη ελέγχου δεν ικανοποιείται πλέον, η εκτέλεση η εκτέλεση του βρόγχου τερματίζεται. 
Αξίζει να τονισθεί ότι κατά την εκτέλεση οποιασδήποτε περίπτωσης, αποκαθίσταται μόνο η ιδιότητα 1. Η αποκατάσταση των ιδιοτήτων 2 και 4 προοικονομούνται στις περιπτώσεις 4 και 2, αντίστοιχα, και ολοκληρώνονται στην τελευταία γραμμή κώδικα της insert_fix_up().

Αφού όπως έχουμε πει, τα red – black trees είναι δυαδικά δέντρα αναζήτησης, αναμένουμε ο χρόνος εκτέλεσης της ΔΙΑΓΡΑΦΗΣ να είναι O(log n), επίσης. Οι συναρτήσεις find_node() και find_predecessor(), που καλούνται στις γραμμές 11 και 22 αντίστοιχα, της delete(), εκτελούν και οι δύο από μία πράξη ΑΝΑΖΗΤΗΣΗ. Ήδη όμως γνωρίζουμε ότι μία τέτοια διαδικασία, για την ολοκλήρωσή της σε δυαδικό δένδρο αναζήτησης, απαιτεί χρόνο O(log n). Όλες οι υπόλοιπες εντολές της delete() απαιτούν χρόνο Ο(1), εκτός από τη κλήση της insert_fix_up(). Εντός της συνάρτησης αποκατάστασης, εκτελείτε κάμποσες φορές ο βρόγχος while και ένας αναχρωματισμός χρόνου Ο(1). Καθώς ο βρόγχος περιλαμβάνει μία σειρά από αναχρωματισμούς, μετατοπίσεις και περιστροφές, το ερώτημα είναι πόσες φορές εκτελείται ο ίδιος ο βρόγχος. Η περίπτωση 4 εκτελείται μία μόνο φορά και ο βρόγχος τερματίζει. Ομοίως, η περίπτωση 3 εκτελείται επίσης μία φορά, αφού μετασχηματίζεται στην περίπτωση 4. Η περίπτωση 1, όπως είπαμε μετασχηματίζεται στις περιπτώσεις 2, 3 και 4. Εάν από την 1, ο έλεγχος μεταφερθεί στις περιπτώσεις 3 ή/και 4, τότε ισχύουν τα παραπάνω. Όταν όμως, μεταφερθεί στην περίπτωση 2, ο χρόνος εκτέλεσής της εξαρτάται από αυτή. Όπως είδαμε παραπάνω, στη περίπτωση 2 αναχρωματίζεται ο «αδελφός» ο έλεγχος μεταφέρεται στον πατρικό του εξεταζόμενου κόμβου. Αυτό πρακτικά σημαίνει ότι μπορεί να ανέβει Ο(log n) φορές προς τα πάνω, και άρα ο βρόγχος να εκτελεστεί και αυτός Ο(log n) φορές. Τελικά, και η delete() εκτελείται σε χρόνο Ο(log n), όπως είχαμε προβλέψει.

