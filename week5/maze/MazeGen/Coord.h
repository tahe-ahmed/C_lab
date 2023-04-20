class Coord
{
	public: 
    	void setX(int i) { x = i;}
    	void setY(int j) { y = j; }
    
    	int getX() const { return x; }
    	int getY() const { return y; }

	private:
		int x;
	    int y;
};
