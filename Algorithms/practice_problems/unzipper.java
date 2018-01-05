import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

// Programm to unzip the a file in java
public class unzipper {

  public static void main(String[] args) {
      File file = new File("/home/staqu/index.android.bundle.zip");
      unzipFile("/home/staqu/","index.android.bundle.zip");
  }

  public static void unzipFile(String path, String zipname) {
        InputStream inputStream;
        ZipInputStream zipInputStream;
        try {
            String filename;
            inputStream = new FileInputStream(path+zipname);
            zipInputStream = new ZipInputStream(inputStream);
            ZipEntry zipEntry;
            byte[] buffer = new byte[1024];
            int count;

            while ((zipEntry = zipInputStream.getNextEntry()) != null) {
                filename = zipEntry.getName();

                if (zipEntry.isDirectory()) {
                    File fmd = new File(path + filename);
                    fmd.mkdirs();
                    continue;
                }

                FileOutputStream fileOutputStream = new FileOutputStream(path + filename);

                while ((count = zipInputStream.read(buffer)) != -1) {
                    fileOutputStream.write(buffer, 0, count);
                }
                fileOutputStream.close();
                zipInputStream.closeEntry();
            }
            zipInputStream.close();
        } catch (FileNotFoundException ex) {
            // Slog.e(Util.TAG_STQ,ex.toString());
            System.out.println("error " + ex.toString());
        } catch (IOException e) {
            // SLog.e(Util.TAG_STQ,e.toString());
            System.out.println("error " + e.toString());
        }
    }

}
