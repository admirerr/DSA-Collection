def exist(board, word):
    dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    
    def f(i, j, idx):
        if idx == len(word):
            return True 
        
        ch = board[i][j]
        board[i][j] = "#"

        for dx, dy in dirs:
            x = i + dx 
            y = j + dy 
            if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == word[idx]:
                if f(x, y, idx + 1):
                    return True 
            
        board[i][j] = ch 
        return False 
    
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == word[0]:
                if f(i, j, 1):
                    return True 
    return False