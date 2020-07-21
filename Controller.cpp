// Controlador:
	// Create visual
	// Create player1, player2
	// Repeat for each player
		// Create player's board
		// Show board
		// Repeat while foundShips is lesser than totalShips
			// Create attackSucessful as false
			// If specialAttack is false
				// Ask player if they want to use the special attack
				// If the answer is true
					// Execute special attack
			// Else 
				// Attack
			// Send response
		
// Create player's board
	// Create board
	// Clear grid
	// Show board
	// Repeat for each ship in that player's list 
		// Choose place for that ship
		// Set ship
		// Update board
	// Ask if they are content with the board
	// If they answer false
		// Ask which ship they want to change
		// Choose place for that ship

// Choose place for that ship:	
	// Create chosen as false
	// While chosen is false
		// Wait for players input
		// Go to that cell
		// Ask if the cell they chose is correct
		// If it is
			// Assign chosen true

// Send response
	// Print totalShips - foundShips for the other player