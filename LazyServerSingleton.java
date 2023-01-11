import java.util.ArrayList;
import java.util.List;

public class LazyServerSingleton {
    private static LazyServerSingleton instance; // Creo una instancia de la clase
    private List<String> servers; // Creo una lista de servidores

    // Creo un constructor privado para que no se pueda instanciar desde fuera de la clase
    private LazyServerSingleton() {
        servers = new ArrayList<>(); // Inicializo la lista de servidores
    }

    // Creo un método público que devuelve la instancia de la clase
    public static LazyServerSingleton getInstance() {
        if (instance == null) {
            instance = new LazyServerSingleton();
        }
        return instance;
    }

    // Creo un método público para añadir servidores a la lista, que recibe un String como parámetro
    public boolean addServer(String server) {
        if (server.startsWith("http://") || server.startsWith("https://")) { // Compruebo que el String empieza por http:// o https://
            if (!servers.contains(server)) { // Compruebo que el servidor no está ya en la lista
                servers.add(server); // Añado el servidor a la lista
                return true;
            }
        }
        return false;
    }

    public List<String> getHttpServers() {
        List<String> httpServers = new ArrayList<>(); // Creo una lista de servidores http
        for (String server : servers) {
            if (server.startsWith("http://")) {
                httpServers.add(server);
            }
        }
        return httpServers; // Devuelvo la lista de servidores http
    }

    public List<String> getHttpsServers() {
        List<String> httpsServers = new ArrayList<>(); // Creo una lista de servidores https
        for (String server : servers) {
            if (server.startsWith("https://")) {
                httpsServers.add(server);
            }
        }
        return httpsServers; // Devuelvo la lista de servidores https
    }
    
    //Metodo para imprimir la lista de servidores, recibe una lista de servidores como parametro
    public void printServers(List<String> servers) {
        for (String server : servers) {
            System.out.println(" - " + server);
        }
    }

    //Funcion Principal
    public static void main(String[] args) {
        LazyServerSingleton server = LazyServerSingleton.getInstance(); // Creo una instancia de la clase
        server.addServer("http://www.pelisplus.com"); // Añado un servidor http
        server.addServer("https://www.google.com"); // Añado un servidor https
        server.addServer("http://www.productosfrikis.com");
        server.addServer("https://www.netflix.com");
        server.addServer("http://www.comoconseguirdinerogratis.com");
        server.addServer("https://www.instagram.com");
        server.addServer("https://www.torrent.com");
        server.addServer("http://www.amazon.com");

        System.out.println("SERVIDORES HTTP:");
        server.printServers(server.getHttpServers()); // Imprimo la lista de servidores http
        System.out.println("\n\nSERVIDORES HTTPS:");
        server.printServers(server.getHttpsServers()); // Imprimo la lista de servidores https
    }
}
