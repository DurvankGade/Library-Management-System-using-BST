<h1>📚 Library Management System</h1>
<hr>
<h4>Welcome to the Library Management System! This project is a simple, yet efficient way to manage a collection of books using a Binary Search Tree (BST). Whether you're organizing a small personal library or a larger collection, this program helps you add, update, search, and delete books with ease.</h4>
<hr>
<h2>Overview</h2>
<br>
<h4>This Library Management System is written in C and utilizes a Binary Search Tree to store and manage books. The program includes a user-friendly interface, making it easy to interact with the system and perform various operations on the library's inventory.</h4>
<hr>
<h2>Features</h2>
<h4><ul><li><b>Add Books:</b> Easily insert new books into the library.
</li>
<li><b>Search Books:</b> Find books by ID, title, or author.</li>

<li><b>Update Books:</b> Modify existing book details.</li>

<li><b>Delete Books:</b> Remove books from the library.</li>

<li><b>Display Books:</b> View all books in the library, sorted by ID.</li></ul></h4>
<hr>
<h2>Code Structure</h2>
<h3>Book Structure:</h3>
<h4>Defines the properties of a book (ID, title, author) and pointers to left and right children in the BST.</h4>
<h3>Functions:</h3>
<h4><pre>
createBook(): Creates a new book node.
insertBook(): Inserts a book into the BST.
searchBookByID(), searchBookByTitle(), searchBookByAuthor(): Functions to search for books.
updateBook(): Updates the details of a book.
deleteBook(): Deletes a book from the BST.
inorderTraversal(): Displays all books in the library.
freeTree(): Frees the allocated memory for the BST.</pre></h4>
<h2>Advantages: </h2>
<h4><ul><li>Efficiency: Binary Search Trees provide efficient insertion, deletion, and search operations.</li>
<li>Scalability: Suitable for managing both small and large collections of books.</li>
<li>Organization: Books are stored in a sorted order by ID, making it easy to browse through the inventory.</li></ul></h4>
