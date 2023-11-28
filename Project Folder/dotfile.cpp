void convexHull::Visualize(){
    std::ofstream dotfile(fileName + ".dot");
    if (dotfile.is_open()){
        dotfile << "graph convexHull";
        dotfile << "{\n";
        for(int i = 0; i < output.size(); i++) {
            dotfile << output[i] << ";\n";
        }
        dotfile << "}\n";
        dotfile.close();
    }
}
