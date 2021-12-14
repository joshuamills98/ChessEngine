CC=g++ -g -Wall


chess: ChessMain.o ChessBoard.o ChessPiece.o King.o Pawn.o Queen.o Rook.o Bishop.o Knight.o ChessConstants.o
	$(CC) ChessMain.o ChessBoard.o ChessPiece.o King.o Pawn.o Queen.o Rook.o Bishop.o Knight.o ChessConstants.o -o chess

ChessMain.o: ChessMain.cpp
	$(CC) -c ChessMain.cpp 

ChessBoard.o: ChessBoard.cpp 
	$(CC) -c ChessBoard.cpp 

ChessPiece.o: ChessPiece.cpp 
	$(CC) -c ChessPiece.cpp 

King.o: King.cpp 
	$(CC) -c King.cpp 

Queen.o: Queen.cpp 
	$(CC) -c Queen.cpp 

Pawn.o: Pawn.cpp 
	$(CC) -c Pawn.cpp 

Rook.o: Rook.cpp 
	$(CC) -c Rook.cpp 

Knight.o: Knight.cpp 
	$(CC) -c Knight.cpp 
	
Bishop.o: Bishop.cpp 
	$(CC) -c Bishop.cpp 

ChessConstants.o: ChessConstants.cpp 
	$(CC) -c ChessConstants.cpp 

tidy:
	rm -f *.o core

clean:
	rm -f main producer consumer *.o core