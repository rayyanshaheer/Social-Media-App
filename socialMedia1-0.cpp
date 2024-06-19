/*
Classes
1. User
2. Post
3. Friend
4. Message
5. SocialMedia

User class:
- name
- username
- password
- dob

Post class:
- post
- username

Friend class:
- username
- friendname

Message class:
- sender
- receiver
- message

SocialMedia class:
- User *users
- Post *posts
- Friend *friends
- Message *messages
- totalUsers
- totalPosts
- totalFriends
- totalMessages

SocialMedia class functions:
- signUp
- signIn
- home
- profile
- inbox
- viewPostsOfFriends
- searchUser
- createPost
- deletePost
- viewMyPosts
- addFriend
- deleteFriend
- viewMyFriends
- viewMessages
- sendMessage
- deleteMessage
- viewProfile
- viewUserInfo
- changePassword

Main function:
- create an object of SocialMedia class
- create a while loop that will run until the user chooses to exit
- inside the while loop, display the menu to the user
- take the user's choice as input
- based on the user's choice, call the appropriate function of the SocialMedia class
- break the loop if the user chooses to exit

Stopping and Clearing function:
- create a function that will stop the program and clear the screen
- this function will be called after each operation to stop the program and wait for the user to press any key to continue
- this function will also clear the screen after the user presses any key to continue

*/

#include <iostream>

using namespace std;

void stoppingAndClearing();

class User
{
    string name;
    string username;
    string password;
    // dob here if you want
public:
    User()
    {
        name = "";
        username = "";
        password = "";
        // dob = "";
    }
    void setName(string n)
    {
        name = n;
    }
    void setUsername(string u)
    {
        username = u;
    }

    void setPassword(string p)
    {
        password = p;
    }
    // set dob here if you want
    string getName()
    {
        return name;
    }
    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }
    // get dob here if you want
};

class Post
{
    string post;
    string username;

public:
    Post()
    {
        post = "";
        username = "";
    }
    void setPost(string p)
    {
        post = p;
    }
    void setUsername(string u)
    {
        username = u;
    }
    string getPost()
    {
        return post;
    }
    string getUsername()
    {
        return username;
    }
};

class Friend
{
    string username;
    string friendname;

public:
    Friend()
    {
        username = "";
        friendname = "";
    }
    void setUsername(string u)
    {
        username = u;
    }
    void setFriendname(string f)
    {
        friendname = f;
    }
    string getUsername()
    {
        return username;
    }
    string getFriendname()
    {
        return friendname;
    }
};

class Message
{
    string sender;
    string receiver;
    string message;

public:
    Message()
    {
        sender = "";
        receiver = "";
        message = "";
    }
    void setSender(string s)
    {
        sender = s;
    }
    void setReceiver(string r)
    {
        receiver = r;
    }
    void setMessage(string m)
    {
        message = m;
    }

    string getSender()
    {
        return sender;
    }
    string getReceiver()
    {
        return receiver;
    }
    string getMessage()
    {
        return message;
    }
};

class SocialMedia
{
    User *users;//pointer to the first object of the array of objects of the class User
    Post *posts;
    Friend *friends;
    Message *messages;

    int totalUsers;
    int totalPosts;
    int totalFriends;
    int totalMessages;

public:
    SocialMedia()
    {
        users = NULL;
        posts = NULL;
        friends = NULL;
        messages = NULL;
        totalUsers = 0;
        totalPosts = 0;
        totalFriends = 0;
        totalMessages = 0;
    }

    // function to sign up a new user
    void signUp()
    {
        cout << "SignUp:" << endl;
        User *temp = new User[totalUsers + 1];
        for (int i = 0; i < totalUsers; i++)
        {
            temp[i] = users[i];
        }
        cout << "Enter your full name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        temp[totalUsers].setName(name);

        char ch;
        string username;
        bool isValid;
        do
        {
            cout << "Enter a username (only alphabets are allowed): ";
            getline(cin, username);

            isValid = true;

            for (char ch : username) // for each character in the string username check if it is an alphabet or not
            {
                if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
                {
                    isValid = false;
                    break;
                }
            }

            if (!isValid)
            {
                cout << "Invalid characters detected! Please enter a valid username with only alphabets." << endl;
            }

        } while (!isValid);
        if (username == "")
        {
            cout << "Username cannot be empty!" << endl;
            return;
        }
        bool unique = true;
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == username)
            {
                unique = false;
                break;
            }
        }
        if (unique)
        {
            temp[totalUsers].setUsername(username);
            cout << "Enter your password: ";
            string password;
            cin >> password;
            temp[totalUsers].setPassword(password);
            // function to set dob here if you want
            totalUsers++;
            if (users != NULL)
            {
                delete[] users;
            }
            users = temp;
            cout << "User registered successfully!" << endl;
            cout << "Total users: " << totalUsers << endl
                 << endl;
            cout << "Your username is: " << username << endl;
            cout << "Your password is: " << password << endl;
            cout << "Please remember your username and password!" << endl;
            cout << "You can now sign in!" << endl
                 << endl;
        }
        else
        {
            cout << "Username already exists!" << endl;
            delete[] temp; // delete the temp array to prevent memory leak
        }
    }

    // Function to sign in an existing user
    void signIn()
    {
        cout << "Enter your username: ";
        string username;
        cin.ignore();
        getline(cin, username);
        cout << "Enter your password: ";
        string password;
        cin >> password;
        bool found = false;
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == username && users[i].getPassword() == password)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "User signed in successfully!" << endl;
            home(username);
        }
        else
        {
            cout << "Invalid username or password!" << endl;
        }
    }

    // Function to display the home menu for a signed-in user
    void home(string username)
    {
        while (true)
        {
            cout << "Welcome " << username << "!" << endl;
            system("cls");
            cout << "1. Go to profile" << endl;
            cout << "2. View inbox messages" << endl;
            cout << "3. View posts of friends" << endl;
            cout << "4. Search a user" << endl;
            cout << "5. Sign out" << endl;
            cout << "Enter your choice: ";
            int choice;
            if (!(cin >> choice))
            {
                cout << "Invalid input! Please enter a valid choice." << endl;
                cin.clear();
                char ch;
                while ((ch = cin.get()) != '\n' && ch != EOF)
                    ;
                continue;
            }
            if (choice == 1)
            {
                system("cls");
                profile(username);
                stoppingAndClearing();
            }
            else if (choice == 2)
            {
                system("cls");
                inbox(username);
                stoppingAndClearing();
            }
            else if (choice == 3)
            {
                system("cls");
                viewPostsOfFriends(username);
                stoppingAndClearing();
            }
            else if (choice == 4)
            {
                system("cls");
                searchUser(username);
                stoppingAndClearing();
            }
            else if (choice == 5)
            {
                break; // this will break the loop and the user will be signed out
            }
            else
            {
                cout << "Invalid choice!" << endl;
                stoppingAndClearing();
            }
        }
    }

    // Function to display the profile menu for a user
    void profile(string username)
    {
        while (true)
        {
            system("cls");
            cout << "Welcome to your profile " << username << "!" << endl;
            cout << "1. Create a post" << endl;
            cout << "2. Delete a post" << endl;
            cout << "3. View my posts" << endl;
            cout << "4. Add a friend" << endl;
            cout << "5. Delete a friend" << endl;
            cout << "6. View my friends" << endl;
            cout << "7. View username, and full name" << endl;
            cout << "8. Change password" << endl; // added option to change password
            cout << "9. Go back" << endl;
            cout << "Enter your choice: ";
            int choice;
            while (!(cin >> choice))
            {
                cout << "invalid input! please enter a valid choice." << endl;
                cin.clear();
                char ch;
                while ((ch = cin.get()) != '\n')
                    ;
            }
            if (choice == 1)
            {
                system("cls");
                cout << "Creating post:" << endl;
                createPost(username);
                stoppingAndClearing();
            }
            else if (choice == 2)
            {
                system("cls");
                cout << "Deleting post:" << endl;
                deletePost(username);
                stoppingAndClearing();
            }
            else if (choice == 3)
            {
                system("cls");
                cout << "My posts:" << endl;
                viewMyPosts(username);
                stoppingAndClearing();
            }
            else if (choice == 4)
            {
                system("cls");
                cout << "Adding friend:" << endl;
                addFriend(username);
                stoppingAndClearing();
            }
            else if (choice == 5)
            {
                system("cls");
                cout << "Deleting friend:" << endl;
                deleteFriend(username);
                stoppingAndClearing();
            }
            else if (choice == 6)
            {
                system("cls");
                cout << "My friends:" << endl;
                viewMyFriends(username);
                stoppingAndClearing();
            }
            else if (choice == 7)
            {
                system("cls");
                cout << "User info:" << endl;
                viewUserInfo(username);
                stoppingAndClearing();
            }
            else if (choice == 8)
            {
                system("cls");
                cout << "Changing password:" << endl;
                changePassword(username); // added function to change password
                stoppingAndClearing();
            }
            else if (choice == 9)
            {
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
                stoppingAndClearing();
            }
        }
    }

    // Function to display the inbox menu for a user
    void inbox(string username)
    {
        while (true)
        {
            cout << "1. View messages" << endl;
            cout << "2. Send a message" << endl;
            cout << "3. Delete a message" << endl;
            cout << "4. Go back" << endl;
            cout << "Enter your choice: ";
            int choice;
            while (!(cin >> choice))
            {
                cout << "invalid input! please enter a valid choice." << endl;
                cin.clear();
                char ch;
                while ((ch = cin.get()) != '\n')
                    ;
            }
            if (choice == 1)
            {
                system("cls");
                viewMessages(username);
                stoppingAndClearing();
            }
            else if (choice == 2)
            {
                system("cls");
                sendMessage(username);
                stoppingAndClearing();
            }
            else if (choice == 3)
            {
                system("cls");
                deleteMessage(username);
                stoppingAndClearing();
            }
            else if (choice == 4)
            {
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
                stoppingAndClearing();
            }
        }
    }

    // Function to view posts of friends
    void viewPostsOfFriends(string username)
    {
        bool found = false;
        for (int i = 0; i < totalFriends; i++)
        {
            if (friends[i].getUsername() == username)
            {
                for (int j = 0; j < totalPosts; j++)
                {
                    if (posts[j].getUsername() == friends[i].getFriendname())
                    {
                        cout << "Post " << j << ":" << endl;
                        cout << "Post: " << posts[j].getPost() << endl;
                        cout << "Username: " << posts[j].getUsername() << endl;
                        cout << endl;
                        found = true;
                    }
                }
            }
        }
        if (!found)
        {
            cout << "No posts found!" << endl;
        }
    }

    // Function to search for a user
    void searchUser(string username)
    {
        cout << "Enter the username of the user you want to search: ";
        string search;
        cin >> search;
        bool found = false;
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == search)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            viewProfile(username, search);
        }
        else
        {
            cout << "No user of this username!" << endl;
        }
    }

    // Function to create a post
    void createPost(string username)
    {
        cout << "Post created successfully!" << endl;
    }

    void deletePost(string username)
    {
        viewMyPosts(username); // Show user's posts
        cout << "Enter the number of the post you want to delete: ";
        int index;

        while (!(cin >> index))
        {
            cout << "invalid input! please enter a valid choice." << endl;
            cin.clear();
            char ch;
            while ((ch = cin.get()) != '\n')
                ;
        }
        index--;
        if (index >= 0 && index < totalPosts)
        {
            if (posts[index].getUsername() == username)
            {
                Post *temp = new Post[totalPosts - 1];
                for (int i = 0, j = 0; i < totalPosts; i++)
                {
                    if (i != index)
                    {
                        temp[j] = posts[i];
                        j++;
                    }
                }
                totalPosts--;
                if (posts != NULL)
                {
                    delete[] posts;
                }
                posts = temp;
                cout << "Post deleted successfully!" << endl;
            }
            else
            {
                cout << "You can only delete your own posts!" << endl;
            }
        }
        else
        {
            cout << "Invalid number!" << endl;
        }
    }
    void viewMyPosts(string username)
    {
        bool found = false;
        for (int i = 0; i < totalPosts; i++)
        {
            if (posts[i].getUsername() == username)
            {
                cout << "Post " << i + 1 << ":" << endl;
                cout << "Post: " << posts[i].getPost() << endl;
                cout << "Username: " << posts[i].getUsername() << endl;
                cout << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No posts found!" << endl;
        }
    }
    void addFriend(string username)
    {
        Friend *temp = new Friend[totalFriends + 1];
        for (int i = 0; i < totalFriends; i++)
        {
            temp[i] = friends[i];
        }
        cout << "Enter the username of the friend you want to add: ";
        string friendname;
        cin >> friendname;
        bool exists = false;
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == friendname)
            {
                exists = true;
                break;
            }
        }
        if (exists && friendname != username) // Check if friendname is not the same as username
        {
            temp[totalFriends].setUsername(username);
            temp[totalFriends].setFriendname(friendname);
            totalFriends++;
            if (friends != NULL)
            {
                delete[] friends;
            }
            friends = temp;
            cout << "Friend added successfully!" << endl;
        }
        else if (friendname == username) // Check if friendname is the same as username
        {
            cout << "You cannot add yourself as a friend!" << endl;
            delete[] temp;
        }
        else
        {
            cout << "No user of this username!" << endl;
            delete[] temp;
        }
    }
    void deleteFriend(string username)
    {
        bool found = false;
        cout << "Your friends: " << endl;
        for (int i = 0; i < totalFriends; i++)
        {
            if (friends[i].getUsername() == username)
            {
                cout << i + 1 << ". " << friends[i].getFriendname() << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No friends found!" << endl;
            return;
        }
        cout << "Enter the number of the friend you want to delete: ";
        int index;
        while (!(cin >> index))
        {
            cout << "invalid input! please enter a valid choice." << endl;
            cin.clear();
            char ch;
            while ((ch = cin.get()) != '\n')
                ;
        }
        index--; // decrementing the index by 1 because the index starts from 0
        if (index >= 0 && index < totalFriends)
        {
            if (friends[index].getUsername() == username)
            {
                Friend *temp = new Friend[totalFriends - 1];
                for (int i = 0, j = 0; i < totalFriends; i++)
                {
                    if (i != index)
                    {
                        temp[j] = friends[i];
                        j++;
                    }
                }
                totalFriends--;
                if (friends != NULL)
                {
                    delete[] friends;
                }
                friends = temp;
                cout << "Friend deleted successfully!" << endl;
            }
            else
            {
                cout << "You can only delete your own friends!" << endl;
            }
        }
        else
        {
            cout << "Invalid number!" << endl;
        }
    }
    void viewMyFriends(string username)
    {
        bool found = false;
        for (int i = 0; i < totalFriends; i++)
        {
            if (friends[i].getUsername() == username)
            {
                cout << "Friend: " << friends[i].getFriendname() << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No friends found!" << endl;
        }
    }
    void viewMessages(string username)
    {
        bool found = false;
        for (int i = 0; i < totalMessages; i++)
        {
            if (messages[i].getReceiver() == username)
            {
                cout << "Message " << i + 1 << ":" << endl;
                cout << "Sender: " << messages[i].getSender() << endl;
                cout << "Message: " << messages[i].getMessage() << endl;
                cout << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No messages found!" << endl;
        }
    }
    void sendMessage(string username)
    {
        Message *temp = new Message[totalMessages + 1]; // this is a dynamic array of messages that will store the messages of the user and the receiver of the message
        for (int i = 0; i < totalMessages; i++)
        {
            temp[i] = messages[i]; // copying the messages from the messages array to the temp array
        }
        cout << "Enter the username of the receiver: ";
        string receiver;
        cin >> receiver;
        bool exists = false;
        for (int i = 0; i < totalUsers; i++) // checking if the user exists or not
        {
            if (users[i].getUsername() == receiver) // if the user exists then the exists will be true
            {
                exists = true;
                break;
            }
        }
        if (exists)
        {
            if (receiver == username) // check if the receiver is the same as the user
            {
                cout << "Do you want to send a message to yourself (y/n)? ";
                char choice;
                cin >> choice;
                if (choice == 'n' || choice == 'N')
                {
                    delete[] temp;
                    return;
                }
            }
            temp[totalMessages].setSender(username); // setting the sender of the message to the username of the user
            temp[totalMessages].setReceiver(receiver);
            cout << "Enter your message: ";
            string message;
            cin.ignore();
            getline(cin, message);
            temp[totalMessages].setMessage(message);
            totalMessages++;
            if (messages != NULL)
            {
                delete[] messages;
            }
            messages = temp;
            cout << "Message sent successfully!" << endl;
        }
        else
        {
            cout << "No user of this username!" << endl;
            delete[] temp;
        }
    }
    void deleteMessage(string username)
    {
        viewMessages(username); // Show user's messages
        if (totalMessages == 0)
        {
            cout << "No messages found!" << endl;//cuz view
            return;
        }
        cout << "Enter the number of the message you want to delete: ";
        int index;
        while (!(cin >> index))
        {
            cout << "invalid input! please enter a valid choice." << endl;
            cin.clear();
            char ch;
            while ((ch = cin.get()) != '\n')
                ;
        }
        index--;
        if (index >= 0 && index < totalMessages)
        {
            if (messages[index].getReceiver() == username)
            {
                Message *temp = new Message[totalMessages - 1];
                for (int i = 0, j = 0; i < totalMessages; i++)
                {
                    if (i != index)
                    {
                        temp[j] = messages[i];
                        j++;
                    }
                }
                totalMessages--;
                if (messages != NULL)
                {
                    delete[] messages;
                }
                messages = temp;
                cout << "Message deleted successfully!" << endl;
            }
            else
            {
                cout << "You can only delete your own messages!" << endl;
            }
        }
        else
        {
            cout << "Invalid number!" << endl;
        }
    }
    void viewProfile(string username, string search)
    {
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == search)
            {
                cout << "Name: " << users[i].getName() << endl;
                cout << "Username: " << users[i].getUsername() << endl;
                // print dob if you want
                break;
            }
        }
        cout << "1. Add as friend" << endl;
        cout << "2. Go back" << endl;
        cout << "Enter your choice: ";
        int choice;
        while (!(cin >> choice))
        {
            cout << "invalid input! please enter a valid choice." << endl;
            cin.clear();
            char ch;
            while ((ch = cin.get()) != '\n')
                ;
        }
        if (choice == 1)
        {
            addFriend(username);
            stoppingAndClearing();
        }
    }

    void viewUserInfo(string username)
    {
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == username)
            {
                cout << "Name: " << users[i].getName() << endl;
                cout << "Username: " << users[i].getUsername() << endl;
                // print dob if you want
                break;
            }
        }
    }

    void changePassword(string username)
    {
        cout << "Enter your new password: ";
        string newPassword;
        cin >> newPassword;
        for (int i = 0; i < totalUsers; i++)
        {
            if (users[i].getUsername() == username)
            {
                users[i].setPassword(newPassword);
                cout << "Password changed successfully!" << endl;
                break;
            }
        }
    }
};

int main()
{
    system("cls");
    SocialMedia socialMedia;
    while (true)
    {
        // system("cls");
        cout << "1. Sign up" << endl;
        cout << "2. Sign in" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        while (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a valid choice." << endl;
            cin.clear(); // clear the error flag of cim
            char ch;
            while ((ch = cin.get()) != '\n') // clear the buffer //cin.get() reads a single character from the input buffer and returns it.
                ;
        }
        if (choice == 1)
        {
            system("cls");
            cout << "Sign Up:" << endl;
            socialMedia.signUp();
            stoppingAndClearing();
        }
        else if (choice == 2)
        {
            system("cls");
            cout << "Sign In:" << endl;
            socialMedia.signIn();
            stoppingAndClearing();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
            stoppingAndClearing();
        }
    }
    return 0;
}

void stoppingAndClearing()
{
    cout << "Press enter key to continue...";
    cin.get();     // this will stop the program and wait for the user to press any key to continue
    cin.ignore();  // this will ignore the next character in the input buffer
    system("cls"); // this will clear the screen
}