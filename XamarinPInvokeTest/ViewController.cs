using System;
using System.Runtime.InteropServices;

using UIKit;

namespace XamarinPInvokeTest
{
	public partial class ViewController : UIViewController
	{
		IntPtr testClassPointer = (IntPtr)0;

		public ViewController (IntPtr handle) : base (handle)
		{
		}

		public override void ViewDidLoad ()
		{
			base.ViewDidLoad ();
			// Perform any additional setup after loading the view, typically from a nib.

			try {
				testClassPointer = Wrapper.CreateTestClass();

				return;
			}
			catch( Exception ) {
				return;
			}
		}

		public override void DidReceiveMemoryWarning ()
		{
			base.DidReceiveMemoryWarning ();
			// Release any cached data, images, etc that aren't in use.
		}

		partial void bGetResult_TouchUpInside (UIButton sender)
		{
			if( testClassPointer != (IntPtr)0 )
			{
				try {
					lbResult.Text = Wrapper.GetNumber( testClassPointer).ToString();
				}
				catch( Exception )
				{
					return;
				}
			}
		}
	}
}

