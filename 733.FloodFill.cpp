class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int original_colour = image[sr][sc];
        image[sr][sc] = newColor;
        if(original_colour != newColor) {
            if(sc+1 < image[0].size() && image[sr][sc+1] == original_colour)
                floodFill(image, sr, sc+1, newColor);

            if(sc-1 >= 0 && image[sr][sc-1] == original_colour)
                floodFill(image, sr, sc-1, newColor);

            if(sr-1 >= 0 && image[sr-1][sc] == original_colour)
                floodFill(image, sr-1, sc, newColor);

            if(sr+1 < image.size() && image[sr+1][sc] == original_colour)
                floodFill(image, sr+1, sc, newColor);
        }
            
        return image;
    }
};