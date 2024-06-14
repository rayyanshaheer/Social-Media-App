# Console-Based Social Media App

This is a console-based Social Media App implemented in C++ for the second semester of an Object-Oriented Programming (OOP) subject. It provides basic functionalities for users to interact with a simulated social network environment, demonstrating various OOP concepts.

## Classes

1. **User**: Represents a user with attributes like name, username, password, and date of birth (dob).
2. **Post**: Represents a post with content and the username of the author.
3. **Friend**: Represents a friendship between two users, identified by their usernames.
4. **Message**: Represents a message with sender, receiver, and message content.
5. **SocialMedia**: Acts as a container for users, posts, friends, and messages, and provides functionalities to manage them.

## SocialMedia Class Functions

- **signUp**: Allows users to create an account.
- **signIn**: Allows users to log in to their account.
- **home**: Displays the main menu and options.
- **profile**: Displays the user's profile information.
- **inbox**: Displays the user's messages.
- **viewPostsOfFriends**: Displays posts from user's friends.
- **searchUser**: Allows users to search for other users.
- **createPost**: Allows users to create a new post.
- **deletePost**: Allows users to delete their own posts.
- **viewMyPosts**: Displays posts authored by the user.
- **addFriend**: Allows users to add friends.
- **deleteFriend**: Allows users to remove friends.
- **viewMyFriends**: Displays the user's friends.
- **viewMessages**: Displays all messages.
- **sendMessage**: Allows users to send messages to other users.
- **deleteMessage**: Allows users to delete messages.
- **viewProfile**: Displays the profile of a specific user.
- **viewUserInfo**: Displays the information of a specific user.
- **changePassword**: Allows users to change their password.

## Main Function

- Creates an object of the `SocialMedia` class.
- Enters a while loop until the user chooses to exit.
- Displays the menu to the user and takes their choice as input.
- Calls the appropriate function of the `SocialMedia` class based on the user's choice.
- Breaks the loop if the user chooses to exit.

## Stopping and Clearing Function

- A function is implemented to stop the program and clear the screen after each operation.
- After the user performs an action, the program pauses and waits for the user to press any key to continue.
- The screen is cleared after the user presses any key to continue.

## Console-Based

This Social Media App operates entirely through the console, providing a text-based interface for users to interact with.

## Usage

To use this Console-Based Social Media App, compile the provided C++ files and run the executable. Follow the on-screen instructions to navigate through the menu and perform various actions such as signing up, signing in, creating posts, adding friends, sending messages, and more.

## Dependencies

This program requires a C++ compiler to build and run.

## Contributions

Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or submit a pull request.
